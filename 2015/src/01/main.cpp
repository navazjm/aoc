#include <bits/stdc++.h>

void partOne(std::string input) {
  int floorCount = 0;
  for (char c : input) {
    if (c == '(') {
      floorCount++;
    } else if (c == ')') {
      floorCount--;
    }
  }
  std::cout << floorCount << std::endl;
}

void partTwo(std::string input) {
  int floorCount = 0;
  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
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

int main() {
  std::string filename = "./input.txt";

  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  std::string fileContents;
  std::string line;

  // Read the file line by line and append each line to the string
  while (std::getline(file, line)) {
    fileContents += line;
    fileContents += '\n'; // Optionally, add newline characters between lines
  }

  // Close the file
  file.close();

  partOne(fileContents);
  partTwo(fileContents);

  return 0;
}
