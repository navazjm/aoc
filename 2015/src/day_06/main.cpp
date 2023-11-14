#include <bits/stdc++.h>

#define SIZE 1000
#define OFF 0
#define ON 1

std::vector<std::string> split(std::string s, char delimiter) {
  std::istringstream iss(s);
  std::vector<std::string> tokens;

  std::string token;
  while (std::getline(iss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

void parseInput(std::vector<std::string> &input) {
  for (int i = 0; i < input.size(); i++) {
    std::vector<std::string> tokens = split(input[i], ' ');
    if (tokens.size() == 4) {
      input[i] = "2 " + tokens[1] + " " + tokens[3];
    } else {
      if (tokens[1] == "off") {
        input[i] = "0 ";
      } else {
        input[i] = "1 ";
      }
      input[i] += tokens[2] + " " + tokens[4];
    }
  }
}

void partOne(const std::vector<std::string> &input) {
  int grid[SIZE][SIZE] = {};
  for (const std::string &s : input) {
    std::vector<std::string> tokens = split(s, ' ');
    std::string action = tokens[0];
    std::vector<std::string> strStartPos = split(tokens[1], ',');
    std::vector<int> startPos = {std::stoi(strStartPos[0]),
                                 std::stoi(strStartPos[1])};
    std::vector<std::string> strEndPos = split(tokens[2], ',');
    std::vector<int> endPos = {std::stoi(strEndPos[0]),
                               std::stoi(strEndPos[1])};

    for (int i = startPos[0]; i <= endPos[0]; i++) {
      for (int j = startPos[1]; j <= endPos[1]; j++) {
        if (action == "2" && grid[i][j] == OFF) {
          grid[i][j] = ON;
        } else if (action == "2" && grid[i][j] == ON) {
          grid[i][j] = OFF;
        } else {
          grid[i][j] = std::stoi(action);
        }
      }
    }
  }
  int onCount = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (grid[i][j] == ON)
        onCount++;
    }
  }
  std::cout << onCount << "\n";
}

void partTwo(const std::vector<std::string> &input) {
  int grid[SIZE][SIZE] = {};
  for (const std::string &s : input) {
    std::vector<std::string> tokens = split(s, ' ');
    std::string action = tokens[0];
    std::vector<std::string> strStartPos = split(tokens[1], ',');
    std::vector<int> startPos = {std::stoi(strStartPos[0]),
                                 std::stoi(strStartPos[1])};
    std::vector<std::string> strEndPos = split(tokens[2], ',');
    std::vector<int> endPos = {std::stoi(strEndPos[0]),
                               std::stoi(strEndPos[1])};

    for (int i = startPos[0]; i <= endPos[0]; i++) {
      for (int j = startPos[1]; j <= endPos[1]; j++) {
        if (action == "0") {
          grid[i][j]--;
          if (grid[i][j] < 0)
            grid[i][j] = 0;
        } else if (action == "1") {
          grid[i][j]++;
        } else {
          grid[i][j]++;
          grid[i][j]++;
        }
      }
    }
  }
  int brightness = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      brightness += grid[i][j];
    }
  }
  std::cout << brightness << "\n";
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

  parseInput(fileContents);

  // Close the file
  file.close();

  partOne(fileContents);
  partTwo(fileContents);

  return 0;
}
