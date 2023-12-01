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
