#! /opt/homebrew/bin/fish

# exit script if any command fails
set -e

set day "day_$argv[1]"
set script_abs_path (dirname (readlink -f (status -f)))
set root_abs_path (dirname $script_abs_path)
set src_abs_path "$root_abs_path/src"
set day_abs_path "$src_abs_path/$day"

# create new day_x dir, copy template folder contents to day_x dir
mkdir $day_abs_path
cp -r $src_abs_path/template/* $day_abs_path
mv $day_abs_path/day_x.h $day_abs_path/$day.h
mv $day_abs_path/day_x.cpp $day_abs_path/$day.cpp

# replace day_x/Day_X with actual day number
set day_cpp_file "$day.cpp"
set day_h_file "$day.h"
set day_namespace "Day_$argv[1]"
set day_def "DAY_$argv[1]_H"
sed -i "s/day_x/$day/g" "$day_abs_path/$day_cpp_file"
sed -i "s/day x/$day/g" "$day_abs_path/$day_cpp_file"
sed -i "s/Day_X/$day_namespace/g" "$day_abs_path/$day_cpp_file"
sed -i "s/Day_X/$day_namespace/g" "$day_abs_path/$day_h_file"
sed -i "s/DAY_X_H/$day_def/g" "$day_abs_path/$day_h_file"

# modify CMakeLists.txt to include new src/day_#/day_#.cpp file, build cmake
set line_number (grep -n "include/aoc.cpp" "$root_abs_path/CMakeLists.txt" | cut -d: -f1)
set src_day_cpp_rel_path "src/$day/$day_cpp_file"
sed -i "$line_number i\\t$src_day_cpp_rel_path" "$root_abs_path/CMakeLists.txt"
cd "$root_abs_path/build"
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cd "$root_abs_path"

# add '#include "day_#/day_#"' to src/main.cpp file
set line_number (grep -n "#include <bits/stdc++.h>" "$src_abs_path/main.cpp" | cut -d: -f1)
set include_day_h_file "#include \"$day/$day_h_file\""
sed -i "$line_number i$include_day_h_file" "$src_abs_path/main.cpp"

# add Day_X::Solution_01 and Day_X::Solution_02 to switch statement in src/main.cpp
set case $argv[1]
set line_number (grep -n "default:" "$src_abs_path/main.cpp" | cut -d: -f1)
set lint_content "  case $case:"
sed -i "$line_number i\\$lint_content" "$src_abs_path/main.cpp"
set line_number (math $line_number + 1)
set lint_content "if (part == 2)"
sed -i "$line_number i\\t$lint_content" "$src_abs_path/main.cpp"
set line_number (math $line_number + 1)
set lint_content "  $day_namespace::Solution_02(file_contents);"
sed -i "$line_number i\\t\\$lint_content" "$src_abs_path/main.cpp"
set line_number (math $line_number + 1)
set lint_content "else"
sed -i "$line_number i\\t$lint_content" "$src_abs_path/main.cpp"
set line_number (math $line_number + 1)
set lint_content "  $day_namespace::Solution_01(file_contents);"
sed -i "$line_number i\\t\\$lint_content" "$src_abs_path/main.cpp"
set line_number (math $line_number + 1)
set lint_content "break;"
sed -i "$line_number i\\t$lint_content" "$src_abs_path/main.cpp"

# open newly created day_#/day_#.cpp file in neovim
cd "$src_abs_path"
nvim "$src_abs_path/$day/$day_cpp_file"
