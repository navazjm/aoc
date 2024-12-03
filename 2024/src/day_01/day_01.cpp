#include "day_01.h"
#include "../aoc.h"
#include <bits/stdc++.h>

void Day_01::Solution_01(const std::vector<std::string> &input) {
    const int size = input.size();
    int left_side[size];
    int right_side[size];

    for (std::size_t i = 0; i < size; i++) {
        std::vector<std::string> values = AOC::Split(input[i], ' ');
        left_side[i] = std::stoi(values[0]);
        right_side[i] = std::stoi(values[1]);
    }

    std::sort(left_side, left_side + size);
    std::sort(right_side, right_side + size);

    int total_distance = 0;
    for (std::size_t i = 0; i < size; i++) {
        int diff = std::abs(left_side[i] - right_side[i]);
        total_distance += diff;
    }
    std::cout << total_distance << "\n";
}

void Day_01::Solution_02(const std::vector<std::string> &input) {
    const int size = input.size();
    int left_side[size];
    int right_side[size];

    for (std::size_t i = 0; i < size; i++) {
        std::vector<std::string> values = AOC::Split(input[i], ' ');
        left_side[i] = std::stoi(values[0]);
        right_side[i] = std::stoi(values[1]);
    }

    int similarities = 0;
    for (std::size_t i = 0; i < size; i++) {
        int num = left_side[i];
        int right_count = std::count(right_side, right_side + size, num);
        similarities += (num * right_count);
    }
    std::cout << similarities << "\n";
}
