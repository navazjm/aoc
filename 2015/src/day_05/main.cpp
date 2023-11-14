#include <bits/stdc++.h>

void partOne(const std::vector<std::string> &input) {
  const std::string vowels = "aeiou";
  const std::string invalidSubstrs[] = {"ab", "cd", "pq", "xy"};

  int niceCount = 0;
  for (const std::string &line : input) {
    int vowelCount = 0;
    for (const char &c : vowels) {
      vowelCount += std::count(line.begin(), line.end(), c);
      if (vowelCount >= 3) {
        break;
      }
    }
    if (vowelCount < 3)
      continue;

    bool foundInvalidSubstr = false;
    for (const std::string &substr : invalidSubstrs) {
      foundInvalidSubstr = line.find(substr) != std::string::npos;
      if (foundInvalidSubstr)
        break;
    }
    if (foundInvalidSubstr)
      continue;

    bool foundConsecutiveChars = false;
    for (int i = 1; i < line.size(); i++) {
      if (line[i - 1] == line[i]) {
        foundConsecutiveChars = true;
        break;
      }
    }
    if (!foundConsecutiveChars)
      continue;

    niceCount++;
  }

  std::cout << niceCount << "\n";
}

void partTwo(const std::vector<std::string> &input) {
  int niceCount = 0;
  for (const std::string &line : input) {
    bool condition1 = false;
    for (int i = 1; i < line.size(); i++) {
      std::string pair = std::string(1, line[i - 1]) + std::string(1, line[i]);
      int occurences = 0;
      size_t pos = line.find(pair);
      while (pos != std::string::npos) {
        ++occurences;
        pos = line.find(pair, pos + pair.length());
      }
      if (occurences > 1) {
        condition1 = true;
        break;
      }
    }
    if (!condition1)
      continue;

    bool condition2 = false;
    for (int i = 1; i < line.size() - 1; i++) {
      char prev = line[i - 1];
      char next = line[i + 1];
      if (prev == next) {
        condition2 = true;
        break;
      }
    }
    if (!condition2)
      continue;

    niceCount++;
  }

  std::cout << niceCount << "\n";
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
