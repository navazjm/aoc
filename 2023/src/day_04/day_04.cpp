#include "day_04.h"
#include "aoc.h"
#include <bits/stdc++.h>

void Day_04::Solution_01(const std::vector<std::string> *input) {
  int total = 0;
  for (const std::string line : *input) {
    int card_points = 0;
    size_t colon_idx = line.find(":");
    std::vector<std::string> halfs =
        AOC::Split(line.substr(colon_idx + 1), '|');
    std::vector<std::string> winning_half_str = AOC::Split(halfs[0], ' ');
    std::set<int> winning_set;
    for (std::string winning_str : winning_half_str) {
      if (winning_str == "")
        continue;
      winning_set.insert(std::stoi(winning_str));
    }
    std::vector<std::string> user_half_str = AOC::Split(halfs[1], ' ');
    for (std::string user_str : user_half_str) {
      if (user_str == "")
        continue;
      int num = std::stoi(user_str);
      if (winning_set.find(num) != winning_set.end()) {
        card_points = card_points == 0 ? 1 : card_points * 2;
      }
    }
    total += card_points;
  }
  std::cout << total << "\n";
}

void Day_04::Solution_02(const std::vector<std::string> *input) {
  std::unordered_map<int, int> scratchcards_count;
  for (int i = 0; i < (*input).size(); i++) {
    scratchcards_count.insert({i + 1, 1});
  }
  for (int i = 0; i < (*input).size(); i++) {
    const std::string line = (*input)[i];
    size_t colon_idx = line.find(":");
    std::vector<std::string> halfs =
        AOC::Split(line.substr(colon_idx + 1), '|');
    std::vector<std::string> winning_half_str = AOC::Split(halfs[0], ' ');
    std::set<int> winning_set;
    for (std::string winning_str : winning_half_str) {
      if (winning_str == "")
        continue;
      winning_set.insert(std::stoi(winning_str));
    }

    int card_num = i + 1;
    int scratchcards_won = 0;
    std::vector<std::string> user_half_str = AOC::Split(halfs[1], ' ');
    for (std::string user_str : user_half_str) {
      if (user_str == "")
        continue;
      int num = std::stoi(user_str);
      if (winning_set.find(num) != winning_set.end()) {
        scratchcards_won += 1;
      }
    }
    for (int j = card_num + 1; j < card_num + 1 + scratchcards_won; j++) {
      for (int k = 0; k < scratchcards_count[card_num]; k++) {
        scratchcards_count[j]++;
      }
    }
  }
  int total_scratchcards = 0;
  for (const auto &card : scratchcards_count) {
    total_scratchcards += card.second;
  }
  std::cout << total_scratchcards << "\n";
}
