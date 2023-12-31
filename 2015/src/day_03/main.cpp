#include <bits/stdc++.h>

void partOne(const std::vector<std::string> &input) {
  std::string s = input[0];
  std::vector<int> cords{0, 0};
  std::set<std::vector<int>> visitedHouses;
  for (const char &c : s) {
    switch (c) {
    case '>':
      cords[0]++;
      break;
    case 'v':
      cords[1]--;
      break;
    case '<':
      cords[0]--;
      break;
    case '^':
      cords[1]++;
      break;
    }
    visitedHouses.insert(cords);
  }
  // add one for the starting cord of 0,0
  std::cout << visitedHouses.size() + 1 << "\n";
}

void partTwo(const std::vector<std::string> &input) {
  std::string s = input[0];
  std::vector<int> santaCords{0, 0};
  std::vector<int> roboSantaCords{0, 0};
  std::set<std::vector<int>> visitedHouses;
  for (int i = 0; i < s.length(); i++) {
    std::vector<int> temp = i % 2 == 0 ? santaCords : roboSantaCords;
    bool isSantaTurn = i % 2 == 0;
    char c = s[i];
    switch (c) {
    case '>':
      temp[0]++;
      break;
    case 'v':
      temp[1]--;
      break;
    case '<':
      temp[0]--;
      break;
    case '^':
      temp[1]++;
      break;
    }
    visitedHouses.insert(temp);
    if (isSantaTurn) {
      santaCords = temp;
    } else {
      roboSantaCords = temp;
    }
  }
  std::cout << visitedHouses.size() << "\n";
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
