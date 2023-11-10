#include <bits/stdc++.h>

void solution(std::string input) {
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

int main() {
  std::string filename = "2015/03/input.txt";

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

  solution(fileLines);

  return 0;
}
