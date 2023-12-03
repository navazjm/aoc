#include "day_02.h"
#include "aoc.h"
#include <algorithm>
#include <bits/stdc++.h>

void Day_02::Solution_01(const std::vector<std::string> *input) {
  int total = 0;
  for (const std::string line : *input) {
    size_t skip_game = 5;
    size_t colon_idx = line.find(":");
    int game_id = std::stoi(line.substr(skip_game, colon_idx));
    bool exceeded_count = false;
    std::vector<std::string> sets = AOC::Split(line.substr(colon_idx + 1), ';');
    for (const std::string set : sets) {
      std::vector<std::string> cubes = AOC::Split(set, ',');
      int red_count = 0, green_count = 0, blue_count = 0;
      for (const std::string cube : cubes) {
        std::string value_str = "";
        for (int i = 0; i < cube.size(); i++) {
          if (!(cube[i] == 'b' || (cube[i] == 'r' && cube[i - 1] == ' ') ||
                cube[i] == 'g' || std::isdigit(cube[i])))
            continue;
          if (std::isdigit(cube[i]))
            value_str += cube[i];
          if (cube[i] == 'r' && cube[i - 1] == ' ') {
            int value = std::stoi(value_str);
            red_count += value;
          }
          if (cube[i] == 'g') {
            int value = std::stoi(value_str);
            green_count += value;
          }
          if (cube[i] == 'b') {
            int value = std::stoi(value_str);
            blue_count += value;
          }
        }
      }
      exceeded_count = red_count > 12 || green_count > 13 || blue_count > 14;
      if (exceeded_count) {
        break;
      }
    }

    if (!exceeded_count) {
      total += game_id;
    }
  }
  std::cout << total << "\n";
}

void Day_02::Solution_02(const std::vector<std::string> *input) {
  int total = 0;
  for (const std::string line : *input) {
    size_t colon_idx = line.find(":");
    bool exceeded_count = false;
    int max_red = 1, max_green = 1, max_blue = 1;
    std::vector<std::string> sets = AOC::Split(line.substr(colon_idx + 1), ';');
    for (const std::string set : sets) {
      std::vector<std::string> cubes = AOC::Split(set, ',');
      int red_count = 0, green_count = 0, blue_count = 0;
      for (const std::string cube : cubes) {
        std::string value_str = "";
        for (int i = 0; i < cube.size(); i++) {
          if (!(cube[i] == 'b' || (cube[i] == 'r' && cube[i - 1] == ' ') ||
                cube[i] == 'g' || std::isdigit(cube[i])))
            continue;
          if (std::isdigit(cube[i]))
            value_str += cube[i];
          if (cube[i] == 'r' && cube[i - 1] == ' ') {
            int value = std::stoi(value_str);
            red_count += value;
            max_red = std::max(max_red, red_count);
          }
          if (cube[i] == 'g') {
            int value = std::stoi(value_str);
            green_count += value;
            max_green = std::max(max_green, green_count);
          }
          if (cube[i] == 'b') {
            int value = std::stoi(value_str);
            blue_count += value;
            max_blue = std::max(max_blue, blue_count);
          }
        }
      }
    }
    total += max_red * max_green * max_blue;
  }
  std::cout << total << "\n";
}
