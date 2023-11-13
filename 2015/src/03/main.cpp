#include <bits/stdc++.h>

void partOne(std::string input) {
  std::vector<int> cords{0, 0};
  std::set<std::vector<int>> visitedHouses;
  for (const char &c : input) {
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

void partTwo(std::string input) {
  std::vector<int> santaCords{0, 0};
  std::vector<int> roboSantaCords{0, 0};
  std::set<std::vector<int>> visitedHouses;
  for (int i = 0; i < input.length(); i++) {
    std::vector<int> temp = i % 2 == 0 ? santaCords : roboSantaCords;
    bool isSantaTurn = i % 2 == 0;
    char c = input[i];
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

int main() {
  std::string filename = "./input.txt";

  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  std::string fileLines;
  std::string line;

  // Read the file line by line and append each line to the string
  while (std::getline(file, line)) {
    fileLines += line + "\n";
  }

  // Close the file
  file.close();

  partOne(fileLines);
  partTwo(fileLines);

  return 0;
}
