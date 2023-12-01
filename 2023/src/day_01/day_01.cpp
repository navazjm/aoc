#include "day_01.h"
#include <bits/stdc++.h>

void Day_01::Solution_01(const std::vector<std::string> *input) {
  int total = 0;
  for (const std::string line : *input) {
    int current_num = 0;
    for (int i = 0; i < line.size(); i++) {
      if (std::isdigit(line[i])) {
        current_num += (line[i] - '0') * 10;
        break;
      }
    }
    for (int i = line.size(); i >= 0; i--) {
      if (std::isdigit(line[i])) {
        current_num += (line[i] - '0');
        break;
      }
    }
    total += current_num;
  }
  std::cout << total << "\n";
}

void Day_01::Solution_02(const std::vector<std::string> *input) {
  int total = 0;
  std::unordered_map<std::string, int> values = {
      {"zero", 0}, {"0", 0},     {"one", 1}, {"1", 1},    {"two", 2},
      {"2", 2},    {"three", 3}, {"3", 3},   {"four", 4}, {"4", 4},
      {"five", 5}, {"5", 5},     {"six", 6}, {"6", 6},    {"seven", 7},
      {"7", 7},    {"eight", 8}, {"8", 8},   {"nine", 9}, {"9", 9},
  };

  for (int i = 0; i < input->size(); i++) {
    const std::string line = (*input)[i];
    std::unordered_map<std::string, int> first_indices;
    std::unordered_map<std::string, int> last_indices;
    for (const auto &pair : values) {
      size_t first_found_pos = line.find(pair.first);
      if (first_found_pos != std::string::npos) {
        first_indices.insert({pair.first, first_found_pos});
      }
      size_t last_found_pos = line.rfind(pair.first);
      if (last_found_pos != std::string::npos) {
        last_indices.insert({pair.first, last_found_pos});
      }
    }
    int min = line.size();
    std::pair<std::string, int> lowest_pair;
    for (const auto &pair : first_indices) {
      if (pair.second <= min) {
        min = pair.second;
        lowest_pair = pair;
      }
    }
    int max = 0;
    std::pair<std::string, int> highest_pair;
    for (const auto &pair : last_indices) {
      if (pair.second >= max) {
        max = pair.second;
        highest_pair = pair;
      }
    }

    std::cout << values[lowest_pair.first] << " " << values[highest_pair.first]
              << " "
              << ((values[lowest_pair.first] * 10) + values[highest_pair.first])
              << "\n";
    total += ((values[lowest_pair.first] * 10) + values[highest_pair.first]);
  }

  std::cout << total << "\n";
}
