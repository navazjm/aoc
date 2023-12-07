#include "day_03.h"
#include <bits/stdc++.h>

bool Is_Adjacent_Special_Char(const std::vector<std::string> *input, int x,
                              int y) {
  if (y > 0 && x > 0 && (*input)[y - 1][x - 1] != '.' &&
      !(std::isdigit((*input)[y - 1][x - 1])))
    return true;
  if (y > 0 && (*input)[y - 1][x] != '.' && !(std::isdigit((*input)[y - 1][x])))
    return true;
  if (y > 0 && x < (*input)[y].size() - 1 && (*input)[y - 1][x + 1] != '.' &&
      !(std::isdigit((*input)[y - 1][x + 1])))
    return true;
  if (x > 0 && (*input)[y][x - 1] != '.' && !(std::isdigit((*input)[y][x - 1])))
    return true;
  if (x < (*input)[y].size() - 1 && (*input)[y][x + 1] != '.' &&
      !(std::isdigit((*input)[y][x + 1])))
    return true;
  if (y < (*input).size() - 1 && x > 0 && (*input)[y + 1][x - 1] != '.' &&
      !(std::isdigit((*input)[y + 1][x - 1])))
    return true;
  if (y < (*input).size() - 1 && (*input)[y + 1][x] != '.' &&
      !(std::isdigit((*input)[y + 1][x])))
    return true;
  if (y < (*input).size() - 1 && x < (*input)[y].size() - 1 &&
      (*input)[y + 1][x + 1] != '.' && !(std::isdigit((*input)[y + 1][x + 1])))
    return true;
  return false;
}

void Day_03::Solution_01(const std::vector<std::string> *input) {
  int total = 0;
  for (int y = 0; y < input->size(); ++y) {
    const std::string line = (*input)[y];
    std::string num_str = "";
    int num = 0;
    bool found_special_char = false;
    for (int x = 0; x < line.size(); ++x) {
      const char c = line[x];
      if (std::isdigit(c)) {
        num_str += line[x];
        if (!found_special_char) {
          found_special_char = Is_Adjacent_Special_Char(input, x, y);
        }
      }
      if (num_str == "") {
        continue;
      }
      if (x == line.size() - 1 || !std::isdigit(line[x + 1])) {
        num = std::stoi(num_str);
        if (found_special_char) {
          total += num;
        }
        num_str = "";
        found_special_char = false;
        num = 0;
      }
    }
  }
  std::cout << total << "\n";
}

std::vector<int> Get_Adjacent_Part_Nums(const std::vector<std::string> *input,
                                        int x, int y) {
  std::vector<int> nums;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (i == 0 && j == 0)
        continue;
      if (y + i < 0 || y + i > (*input).size())
        continue;
      if (x + j < 0 || x + j > (*input)[y + i].size())
        continue;
      if (!std::isdigit((*input)[y + i][x + j]))
        continue;
      if (j != 1 && std::isdigit((*input)[y + i][x + j + 1]))
        continue;

      std::string num_str = "";
      num_str += (*input)[y + i][x + j];
      int left = 1;
      while (x + j - left >= 0 && x + j - left < (*input)[y + i].size() &&
             std::isdigit((*input)[y + i][x + j - left])) {
        num_str += (*input)[y + i][x + j - left++];
      }
      std::reverse(num_str.begin(), num_str.end());
      int right = 1;
      while (x + j + right >= 0 && x + j + right < (*input)[y + i].size() &&
             std::isdigit((*input)[y + i][x + j + right])) {
        num_str += (*input)[y + i][x + j + right++];
      }
      int num = std::stoi(num_str);
      nums.push_back(num);
    }
  }
  return nums;
}

void Day_03::Solution_02(const std::vector<std::string> *input) {
  int total = 0;
  for (int y = 0; y < input->size(); ++y) {
    const std::string line = (*input)[y];
    for (int x = 0; x < line.size(); ++x) {
      const char c = line[x];
      if (c != '*') {
        continue;
      }
      std::vector<int> adjacent_part_nums = Get_Adjacent_Part_Nums(input, x, y);
      if (adjacent_part_nums.size() != 2)
        continue;
      total += adjacent_part_nums[0] * adjacent_part_nums[1];
    }
  }
  std::cout << total << "\n";
}
