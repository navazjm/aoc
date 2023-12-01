# AOC 2023 Solutions

My goal this year to actually complete each solution for each day.
I am not worried about having the most optimized solution, but rather
have perseverance to complete each solution. Also, I am not worried about
making it on the leaderboards, but I won't not be happy if I do..

## Build from source

- clone the repo

```bash
git clone https://github.com/navazjm/aoc
```

- cd into aoc 2023

```bash
cd path/to/aoc/2023
```

### CMake

- create and cd into build dir

```bash
mkdir build && cd build
```

-- run cmake
```bash
cmake ..
```

- run make
```bash
make
```

### GCC compiler

- Don't want to use CMake??

```bash
g++ -std=c++11 -o aoc_2023 $(find src -type f -name "*.cpp" ! -path "src/template/*") -Iinclude
```

## Run from source

- After building from source, run AOC 2023:

```bash
./aoc_2023 <1-25> <1/2> <0/1>
```

### Command-line arguments

- <1-25> : Represents the day of the advent calendar

- <1/2> : Solution part number (1 or 2)

- <0/1> : use input (0) or sample (1) txt file for input data 

- EXAMPLE: Run day 3 part 1 input solution

```bash
./aoc_2023 3 1 0
```

- EXAMPLE: Run day 7 part 2 sample solution

```bash
./aoc_2023 7 2 1
```

