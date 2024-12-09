#ifndef DAY_05_H
#define DAY_05_H

#include <bits/stdc++.h>

namespace Day_05 {
void Solution_01(const std::vector<std::string> &input);
void Solution_02(const std::vector<std::string> &input);
} // namespace Day_05

std::vector<std::size_t> _incorrect_order(const std::vector<std::string> &values,
                                          std::unordered_map<std::string, std::vector<std::string>> order);

#endif // DAY_05_H
