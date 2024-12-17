#include "day_08.h"

void Day_08::Solution_01(const std::vector<std::string> &input) {
    std::size_t row_count = input.size();
    std::size_t col_count = input[0].size();
    std::set<std::vector<int>> seen_locations;
    for (std::size_t row = 0; row < row_count; row++) {
        for (std::size_t col = 0; col < col_count; col++) {
            if (input[row][col] == '.')
                continue;
            char antenna_freq = input[row][col];
            for (std::size_t y = 0; y < row_count; y++) {
                for (std::size_t x = 0; x < col_count; x++) {
                    if (y == row && x == col)
                        continue;
                    if (input[y][x] == antenna_freq) {
                        int new_y = y + (y - row);
                        int new_x = x + (x - col);
                        if (new_y >= 0 && new_y < row_count && new_x >= 0 && new_x < col_count &&
                            seen_locations.count({new_x, new_y}) == 0) {
                            seen_locations.insert({new_x, new_y});
                        }
                        new_y = row + (row - y);
                        new_x = col + (col - x);
                        if (new_y >= 0 && new_y < row_count && new_x >= 0 && new_x < col_count &&
                            seen_locations.count({new_x, new_y}) == 0) {
                            seen_locations.insert({new_x, new_y});
                        }
                    }
                }
            }
        }
    }
    std::cout << seen_locations.size() << "\n";
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_08::Solution_02(const std::vector<std::string> &input) {
    std::size_t row_count = input.size();
    std::size_t col_count = input[0].size();
    std::set<std::vector<int>> seen_locations;
    for (int y1 = 0; y1 < row_count; y1++) {
        for (int x1 = 0; x1 < col_count; x1++) {
            if (input[y1][x1] == '.')
                continue;
            char antenna_freq = input[y1][x1];
            seen_locations.insert({y1, x1});
            for (int y2 = 0; y2 < row_count; y2++) {
                for (int x2 = 0; x2 < col_count; x2++) {
                    if (y2 == y1 && x2 == x1)
                        continue;
                    if (input[y2][x2] == antenna_freq) {
                        int diff_y = y2 - y1;
                        int diff_x = x2 - x1;

                        int new_y = y2 + diff_y;
                        int new_x = x2 + diff_x;
                        while (new_y >= 0 && new_y < row_count && new_x >= 0 && new_x < col_count) {
                            seen_locations.insert({new_y, new_x});
                            new_y += diff_y;
                            new_x += diff_x;
                        }
                        new_y = y1 - diff_y;
                        new_x = x1 - diff_x;
                        while (new_y >= 0 && new_y < row_count && new_x >= 0 && new_x < col_count) {
                            seen_locations.insert({new_y, new_x});
                            new_y -= diff_y;
                            new_x -= diff_x;
                        }
                    }
                }
            }
        }
    }
    std::cout << seen_locations.size() << "\n";
}
