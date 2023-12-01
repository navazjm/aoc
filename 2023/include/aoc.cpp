#include "aoc.h"

std::vector<std::string> AOC::Split(const std::string &str,
                                    const char delimiter) {
  return {};
}

std::vector<std::string> *AOC::Get_File_Contents(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    return nullptr;
  }

  std::vector<std::string> *fileContents = new std::vector<std::string>;
  std::string line;
  while (std::getline(file, line)) {
    fileContents->push_back(line);
  }
  file.close();

  return fileContents;
}

std::string AOC::Get_Solution_Test_Case_File_Path(int day,
                                                  int useSampleTxtFile) {
  std::string filePath =
      std::string("../src/day_") + (day < 10 ? "0" : "") + std::to_string(day);

  if (useSampleTxtFile) {
    return filePath + "/sample.txt";
  }

  return filePath + "/input.txt";
}
