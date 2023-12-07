#include "aoc.h"
#include "day_01/day_01.h"
#include "day_02/day_02.h"
#include "day_03/day_03.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 4) {
    std::cerr
        << "Usage: <day 1-25> <part 1 or 2> <input or sample data (0 or 1)>\n";
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

  int useSampleFileTxt = 0;
  if (argv[3]) {
    useSampleFileTxt = std::atoi(argv[3]);
  }
  if (useSampleFileTxt != 0 && useSampleFileTxt != 1) {
    std::cerr << "Invalid useInputFileTxt. Please choose either 0 or 1.\n";
    return 1;
  }
  std::string filename =
      AOC::Get_Solution_Test_Case_File_Path(day, useSampleFileTxt);
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
  case 2:
    if (part == 2)
      Day_02::Solution_02(fileContents);
    else
      Day_02::Solution_01(fileContents);
    break;
  case 3:
    if (part == 2)
      Day_03::Solution_02(fileContents);
    else
      Day_03::Solution_01(fileContents);
    break;
  default:
    std::cout << "Could not find solution to Day " << day << " Part " << part
              << ".\n";
  }

  delete fileContents;

  return 0;
}
