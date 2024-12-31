#include "day_10.h"

void Day_10::Solution_01(const std::vector<std::string> &input) {
    std::cout << "Day 10 Part 1\n";
    // must start at 0, can only increase by a height of 1. Ex, 0->1 good, 1->2 good, 1->3 bad.
    // count how many hiking trails go from 0 to 9, only by going up, down, left, or right.
    std::size_t total_trailheads = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (static_cast<int>(input[i][j]) - '0' != 0)
                continue;
            std::set<std::vector<int>> seen_locations;
            calculate_trailheads(seen_locations, input, i, j);
            total_trailheads += seen_locations.size();
        }
    }
    std::cout << total_trailheads << "\n";
}

void calculate_trailheads(std::set<std::vector<int>> &seen_locations, const std::vector<std::string> &grid, int row,
                          int col) {

    int curr_val = static_cast<int>(grid[row][col]) - '0';
    if (curr_val == 9 && seen_locations.count({row, col}) == 0) {
        seen_locations.insert({row, col});
        return;
    }

    if (row > 0) {
        int next_val = static_cast<int>(grid[row - 1][col]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(seen_locations, grid, row - 1, col);
        }
    }

    if (col < grid[0].size() - 1) {
        int next_val = static_cast<int>(grid[row][col + 1]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(seen_locations, grid, row, col + 1);
        }
    }

    if (row < grid.size() - 1) {
        int next_val = static_cast<int>(grid[row + 1][col]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(seen_locations, grid, row + 1, col);
        }
    }

    if (col > 0) {
        int next_val = static_cast<int>(grid[row][col - 1]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(seen_locations, grid, row, col - 1);
        }
    }
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_10::Solution_02(const std::vector<std::string> &input) {
    std::cout << "Day 10 Part 2\n";
    std::size_t total_trailheads = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (static_cast<int>(input[i][j]) - '0' != 0)
                continue;
            calculate_trailheads(total_trailheads, input, i, j);
        }
    }
    std::cout << total_trailheads << "\n";
}

void calculate_trailheads(std::size_t &total_trailheads, const std::vector<std::string> &grid, int row, int col) {

    int curr_val = static_cast<int>(grid[row][col]) - '0';
    if (curr_val == 9) {
        total_trailheads++;
        return;
    }

    if (row > 0) {
        int next_val = static_cast<int>(grid[row - 1][col]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(total_trailheads, grid, row - 1, col);
        }
    }

    if (col < grid[0].size() - 1) {
        int next_val = static_cast<int>(grid[row][col + 1]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(total_trailheads, grid, row, col + 1);
        }
    }

    if (row < grid.size() - 1) {
        int next_val = static_cast<int>(grid[row + 1][col]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(total_trailheads, grid, row + 1, col);
        }
    }

    if (col > 0) {
        int next_val = static_cast<int>(grid[row][col - 1]) - '0';
        if (curr_val + 1 == next_val) {
            calculate_trailheads(total_trailheads, grid, row, col - 1);
        }
    }
}
