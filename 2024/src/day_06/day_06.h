#ifndef DAY_06_H
#define DAY_06_H

#include <bits/stdc++.h>

namespace Day_06 {
void Solution_01(const std::vector<std::string> &input);
void Solution_02(const std::vector<std::string> &input);
} // namespace Day_06

struct Pos {
    int row;
    int col;
};

bool _detect_loop(std::vector<std::string> &grid, const Pos &ar_pos);

#endif // DAY_06_H
