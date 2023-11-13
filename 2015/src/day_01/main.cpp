#include <bits/stdc++.h>

void partOne(const std::vector<std::string> &input) {
  std::string s = input[0];
  int floorCount = 0;
  for (char c : s) {
    if (c == '(') {
      floorCount++;
    } else if (c == ')') {
      floorCount--;
    }
  }
  std::cout << floorCount << std::endl;
}

void partTwo(const std::vector<std::string> &input) {
  std::string s = input[0];
  int floorCount = 0;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if (c == '(') {
      floorCount++;
    } else if (c == ')') {
      floorCount--;
    }

    if (floorCount == -1) {
      std::cout << i + 1 << std::endl;
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename.txt>" << std::endl;
    return 1;
  }
  std::string filename = argv[1];

  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  std::vector<std::string> fileContents;
  std::string line;

  while (std::getline(file, line)) {
    fileContents.push_back(line);
  }

  file.close();

  partOne(fileContents);
  partTwo(fileContents);

  return 0;
}
