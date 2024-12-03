# AOC 2023 Solutions

## Directory Tree

```
project-root/2024/
|-- scripts/
| |-- add-day.sh # script to automate adding a new day_XX solution
|-- src/
| |-- aoc.cpp # common utility functions
| |-- aoc.h
| |-- day_XX/
| | |-- day_XX.cpp
| | |-- day_XX.h
| | |-- input.txt
| | |-- sample.txt
| |-- main.cpp
|-- CMakeLists.txt
|-- README.md

```

*NOTE*: To respect AoC T&C, this repo does not contain any puzzle input files. Also, each 
AoC user has their own unique puzzle input. Therefore, you will have to create and populate 
your own input.txt file inside each `src/day_xx` directory. 

## Build from source

- clone the repo

```bash
git clone https://github.com/navazjm/aoc
```

- cd into aoc 2024

```sh
cd path/to/aoc/2023
```

### CMake

- create and cd into build dir

```sh
mkdir build && cd build
```

-- run cmake

```sh
cmake ..
```

- run make

```sh
make
```

### GCC compiler

- Don't want to use CMake??

```sh
g++ -std=c++17 -o aoc_2024 $(find src -type f -name "*.cpp" ! -path "src/template/*") -Iinclude
```

## Run from source

- After building from source, run AOC 2024:

```sh
./aoc_2024 <1-25> <1/2> <0/1>
```

### Command-line arguments

- <1-25> : Represents the day of the advent calendar

- <1/2> : Solution part number (1 or 2)

- <0/1> : use input (0) or sample (1) txt file for input data 

- EXAMPLE: Run day 3 part 1 input solution

```sh
./aoc_2024 3 1 0
```

- EXAMPLE: Run day 7 part 2 sample solution

```sh
./aoc_2024 7 2 1
```

