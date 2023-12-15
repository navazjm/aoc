#include "day_09.h"
#include "aoc.h"
#include <bits/stdc++.h>
#include <string>

void Day_09::Solution_01(const std::vector<std::string> *input) {
  std::vector<int> history_values;
  for (const std::string &line : (*input)) {
    std::vector<std::string> num_strs = AOC::Split(line, ' ');
    std::vector<std::vector<int>> report(1);
    for (const std::string &num_str : num_strs) {
      int num = std::stoi(num_str);
      report[0].push_back(num);
    }

    bool last_report_is_all_zeros = false;
    while (!last_report_is_all_zeros) {
      size_t prev_report_idx = report.size() - 1;
      std::vector<int> new_report;
      for (int i = 1; i < report[prev_report_idx].size(); i++) {
        int diff = report[prev_report_idx][i] - report[prev_report_idx][i - 1];
        new_report.push_back(diff);
      }
      report.push_back(new_report);

      int zero_count = 0;
      for (const int &num : new_report) {
        if (num == 0)
          zero_count++;
      }
      last_report_is_all_zeros = zero_count == new_report.size();
    }

    int history_value = 0;
    for (const std::vector<int> &rep : report) {
      history_value += rep[rep.size() - 1];
    }
    history_values.push_back(history_value);
  }
  int total_history = 0;
  for (const int &history : history_values) {
    total_history += history;
  }
  std::cout << total_history << "\n";
}

void Day_09::Solution_02(const std::vector<std::string> *input) {
  std::vector<int> history_values;
  for (const std::string &line : (*input)) {
    std::vector<std::string> num_strs = AOC::Split(line, ' ');
    std::vector<std::vector<int>> report(1);
    for (const std::string &num_str : num_strs) {
      int num = std::stoi(num_str);
      report[0].push_back(num);
    }

    bool last_report_is_all_zeros = false;
    while (!last_report_is_all_zeros) {
      size_t prev_report_idx = report.size() - 1;
      std::vector<int> new_report;
      for (int i = 1; i < report[prev_report_idx].size(); i++) {
        int diff = report[prev_report_idx][i] - report[prev_report_idx][i - 1];
        new_report.push_back(diff);
      }
      report.push_back(new_report);

      int zero_count = 0;
      for (const int &num : new_report) {
        if (num == 0)
          zero_count++;
      }
      last_report_is_all_zeros = zero_count == new_report.size();
    }

    int history_value = 0;
    for (int i = report.size() - 1; i >= 0; i--) {
      const std::vector<int> &rep = report[i];
      history_value = rep[0] - history_value;
    }
    history_values.push_back(history_value);
  }
  int total_history = 0;
  for (const int &history : history_values) {
    total_history += history;
  }
  std::cout << total_history << "\n";
}
