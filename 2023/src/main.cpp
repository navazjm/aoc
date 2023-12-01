#include "aoc.h"
#include "day_01/day_01.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[3]
              << "<day 1-25> <part 1 or 2> <filename.txt>" << std::endl;
    return 1;
  }
  int day = std::atoi(argv[1]);
  if (day < 1 || day > 25) {
    std::cerr << "Invalid day. Please choose a number in the range 1-25.\n";
    return 1;
  }

  int part = std::atoi(argv[2]);
  if (part != 1 && part != 2) {
    std::cerr << "Invalid part. Please choose either 1 or 2.\n";
    return 1;
  }

  std::string filename = argv[3];
  std::vector<std::string> *fileContents = AOC::Get_File_Contents(filename);
  if (!fileContents) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  switch (day) {
  case 1:
    if (part == 2)
      Day_01::Solution_02(fileContents);
    else
      Day_01::Solution_01(fileContents);
    break;
  default:
    std::cout << "Could not find solution to Day " << day << " Part " << part
              << ".\n";
  }

  delete fileContents;

  return 0;
}
