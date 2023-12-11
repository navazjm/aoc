#include "day_06.h"
#include "aoc.h"
#include <bits/stdc++.h>

#define ll long long

void Day_06::Solution_01(const std::vector<std::string> *input) {
  std::vector<int> time_values;
  std::vector<int> dist_values;

  size_t colon_idx = (*input)[0].find(":");
  std::vector<std::string> time_strs =
      AOC::Split((*input)[0].substr(colon_idx + 1), ' ');
  for (const std::string time_str : time_strs) {
    if (time_str == "")
      continue;
    time_values.push_back(std::stoi(time_str));
  }
  colon_idx = (*input)[1].find(":");
  std::vector<std::string> dist_strs =
      AOC::Split((*input)[1].substr(colon_idx + 1), ' ');
  for (const std::string dist_str : dist_strs) {
    if (dist_str == "")
      continue;
    dist_values.push_back(std::stoi(dist_str));
  }

  int total_beat_record = 1;
  for (int i = 0; i < time_values.size(); i++) {
    int time = time_values[i];
    int current_break_record = 0;
    for (int j = 1; j <= time; j++) {
      int val = j * (time - j);
      if (val > dist_values[i]) {
        current_break_record++;
      }
    }
    total_beat_record *= current_break_record;
  }
  std::cout << total_beat_record << "\n";
}

void Day_06::Solution_02(const std::vector<std::string> *input) {
  std::string time_str;
  size_t colon_idx = (*input)[0].find(":");
  std::vector<std::string> time_str_values =
      AOC::Split((*input)[0].substr(colon_idx + 1), ' ');
  for (const std::string time_str_value : time_str_values) {
    if (time_str_value == "")
      continue;
    time_str += time_str_value;
  }
  ll time = std::stoll(time_str);

  std::string dist_str;
  colon_idx = (*input)[1].find(":");
  std::vector<std::string> dist_str_values =
      AOC::Split((*input)[1].substr(colon_idx + 1), ' ');
  for (const std::string dist_str_value : dist_str_values) {
    if (dist_str_value == "")
      continue;
    dist_str += dist_str_value;
  }
  ll dist = std::stoll(dist_str);

  ll total = 0;
  for (ll j = 1; j <= time; j++) {
    ll val = j * (time - j);
    if (val >= dist) {
      total++;
    }
  }
  std::cout << total << "\n";
}
