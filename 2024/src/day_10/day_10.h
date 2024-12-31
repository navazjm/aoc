#ifndef DAY_10_H
#define DAY_10_H

#include <bits/stdc++.h>

namespace Day_10 {
void Solution_01(const std::vector<std::string> &input);
void Solution_02(const std::vector<std::string> &input);
} // namespace Day_10

void calculate_trailheads(std::set<std::vector<int>> &seen_locations, const std::vector<std::string> &grid, int row,
                          int col);
void calculate_trailheads(std::size_t &total_trailheads, const std::vector<std::string> &grid, int row, int col);

#endif // DAY_10_H
