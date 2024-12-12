#include "day_07.h"
#include "../aoc.h"

void Day_07::Solution_01(const std::vector<std::string> &input) {
    ll total_calibration_result = 0;
    for (const std::string &line : input) {
        std::vector<std::string> parts = AOC::Split(line, ':');
        ll test_val = std::stoll(parts[0]);
        std::vector<std::string> parts_right = AOC::Split(parts[1], ' ');
        if (_true_equation(parts_right, test_val))
            total_calibration_result += test_val;
    }
    std::cout << total_calibration_result << "\n";
}

bool _true_equation(const std::vector<std::string> &values, const ll &test_val) {
    ll first_num = std::stoi(values[0]);
    std::vector<ll> totals{first_num};
    for (std::size_t i = 1; i < values.size(); i++) {
        std::vector<ll> new_totals;
        int n = std::stoi(values[i]);
        for (const ll &tot : totals) {
            new_totals.push_back(tot + n);
            new_totals.push_back(tot * n);
        }
        totals = new_totals;
    }
    for (const ll &tot : totals) {
        if (tot == test_val)
            return true;
    }
    return false;
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_07::Solution_02(const std::vector<std::string> &input) {
    std::cout << "Day 07 Part 02\n";
    ll total_calibration_result = 0;
    for (const std::string &line : input) {
        std::vector<std::string> parts = AOC::Split(line, ':');
        ll test_val = std::stoll(parts[0]);
        std::vector<std::string> parts_right = AOC::Split(parts[1], ' ');
        if (_true_equation_s2(parts_right, test_val))
            total_calibration_result += test_val;
    }
    std::cout << total_calibration_result << "\n";
}

bool _true_equation_s2(const std::vector<std::string> &values, const ll &test_val) {
    ll first_num = std::stoi(values[0]);
    std::vector<ll> totals{first_num};
    for (std::size_t i = 1; i < values.size(); i++) {
        std::vector<ll> new_totals;
        int n = std::stoi(values[i]);
        for (const ll &tot : totals) {
            new_totals.push_back(tot + n);
            new_totals.push_back(tot * n);
            std::string s = std::to_string(tot) + std::to_string(n);
            new_totals.push_back(std::stoll(s));
        }
        totals = new_totals;
    }
    for (const ll &tot : totals) {
        if (tot == test_val)
            return true;
    }
    return false;
}
