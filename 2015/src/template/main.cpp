#include <bits/stdc++.h>

void partOne(std::string input) { std::cout << input << "\n"; }

void partTwo(std::string input) { std::cout << input << "\n"; }

int main(int argc, char *argv[]) {
  // Check if a file path is provided as a command-line argument
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename.txt>" << std::endl;
    return 1; // Exit with an error code
  }
  std::string filename = argv[1];

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
