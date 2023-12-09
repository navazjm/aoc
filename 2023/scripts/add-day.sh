#! /usr/bin/zsh

# exit sh script if any command fails
set -e

day="day_"$1
script_abs_path="$(dirname "$(readlink -f "$0")")"
root_abs_path="$(dirname "$script_abs_path")"
src_abs_path="$root_abs_path/src"
day_abs_path="$src_abs_path/$day"

# create new day_x dir, copy template folder contents to day_x dir
mkdir $day_abs_path
cp -r $src_abs_path/template/* $day_abs_path
mv $day_abs_path/day_x.h $day_abs_path/$day.h
mv $day_abs_path/day_x.cpp $day_abs_path/$day.cpp

# replace day_x/Day_X with actual day number
day_cpp_file="$day.cpp"
day_h_file="$day.h"
day_namespace="Day_"$1
day_def="DAY_"$1"_H"
sed -i "s/day_x/$day/g" "$day_abs_path/$day_cpp_file"
sed -i "s/day x/$day/g" "$day_abs_path/$day_cpp_file"
sed -i "s/Day_X/$day_namespace/g" "$day_abs_path/$day_cpp_file"
sed -i "s/Day_X/$day_namespace/g" "$day_abs_path/$day_h_file"
sed -i "s/DAY_X_H/$day_def/g" "$day_abs_path/$day_h_file"

# modify CMakeLists.txt to include new src/day_#/day_#.cpp file, build cmake
line_number=$(grep -n "include/aoc.cpp" "$root_abs_path/CMakeLists.txt" | cut -d: -f1)
src_day_cpp_rel_path="src/$day/$day_cpp_file"
sed -i "${line_number}i\\\t${src_day_cpp_rel_path}" "$root_abs_path/CMakeLists.txt"
cd "$root_abs_path"/build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..

# add '#include "day_#/day_#"' to src/main.cpp file
line_number=$(grep -n "#include <bits/stdc++.h>" "$src_abs_path/main.cpp" | cut -d: -f1)
include_day_h_file="#include \"$day/$day_h_file\""
sed -i "${line_number}i${include_day_h_file}" "$src_abs_path/main.cpp"

# add Day_X::Solution_01 and Day_X::Solution_02 to switch statement in src/main.cpp
case=$1
line_number=$(grep -n "default:" "$src_abs_path/main.cpp" | cut -d: -f1)
lint_content="  case $case:"
sed -i "${line_number}i\\${lint_content}" "$src_abs_path/main.cpp"
line_number=$((line_number + 1))
lint_content="if (part == 2)"
sed -i "${line_number}i\\\t${lint_content}" "$src_abs_path/main.cpp"
line_number=$((line_number + 1))
lint_content="  $day_namespace::Solution_02(file_contents);"
sed -i "${line_number}i\\\t\\${lint_content}" "$src_abs_path/main.cpp"
line_number=$((line_number + 1))
lint_content="else"
sed -i "${line_number}i\\\t${lint_content}" "$src_abs_path/main.cpp"
line_number=$((line_number + 1))
lint_content="  $day_namespace::Solution_01(file_contents);"
sed -i "${line_number}i\\\t\\${lint_content}" "$src_abs_path/main.cpp"
line_number=$((line_number + 1))
lint_content="break;"
sed -i "${line_number}i\\\t${lint_content}" "$src_abs_path/main.cpp"

