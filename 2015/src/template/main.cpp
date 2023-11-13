#include <bits/stdc++.h>

void partOne(const std::vector<std::string> &input) {
  for (const std::string &line : input) {
    std::cout << line << "\n";
  }
  std::cout << "\n";
}

void partTwo(const std::vector<std::string> &input) {
  for (const std::string &line : input) {
    std::cout << line << "\n";
  }
  std::cout << "\n";
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

  // Close the file
  file.close();

  partOne(fileContents);
  partTwo(fileContents);

  return 0;
}
