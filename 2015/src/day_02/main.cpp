#include <bits/stdc++.h>

void partOne(const std::vector<std::string> &input) {
  long total = 0;
  for (std::string line : input) {
    std::vector<int> dimensions;
    std::istringstream ss(line);
    std::string token;

    while (std::getline(ss, token, 'x')) {
      dimensions.push_back(std::stoi(token));
    }

    int l = dimensions[0];
    int w = dimensions[1];
    int h = dimensions[2];
    int s1 = l * w;
    int s2 = h * w;
    int s3 = h * l;
    int minimumValue = std::min(s1, std::min(s2, s3));
    int area = (2 * l * w) + (2 * w * h) + (2 * h * l) + minimumValue;
    total += area;
  }

  std::cout << total << std::endl;
}

void partTwo(const std::vector<std::string> &input) {
  long total = 0;
  for (std::string line : input) {
    std::vector<int> dimensions;
    std::istringstream ss(line);
    std::string token;

    while (std::getline(ss, token, 'x')) {
      dimensions.push_back(std::stoi(token));
    }

    int l = dimensions[0];
    int w = dimensions[1];
    int h = dimensions[2];
    int cubFt = l * w * h;
    std::sort(dimensions.begin(), dimensions.end());
    int ribbonLen =
        dimensions[0] + dimensions[0] + dimensions[1] + dimensions[1] + cubFt;
    total += ribbonLen;
  }

  std::cout << total << std::endl;
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

  std::vector<std::string> fileLines;
  std::string line;

  while (std::getline(file, line)) {
    fileLines.push_back(line);
  }

  file.close();

  partOne(fileLines);
  partTwo(fileLines);

  return 0;
}
