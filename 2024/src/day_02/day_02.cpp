#include "day_02.h"
#include "../aoc.h"

void Day_02::Solution_01(const std::vector<std::string> &input) {
    int total_safe = 0;
    for (const std::string &line : input) {
        std::vector<std::string> values = AOC::Split(line, ' ');
        if (_check_is_safe(values))
            total_safe++;
    }
    std::cout << total_safe << "\n";
}

void Day_02::Solution_02(const std::vector<std::string> &input) {
    int total_safe = 0;
    for (const std::string &line : input) {
        std::vector<std::string> values = AOC::Split(line, ' ');
        if (_check_is_safe(values)) {
            total_safe++;
            continue;
        }
        for (std::size_t i = 0; i < values.size(); i++) {
            // copy contents of og vector into new vector, excluding the current index
            std::vector<std::string> new_values;
            size_t currentIndex = 0;
            std::copy_if(values.begin(), values.end(), std::back_inserter(new_values),
                         [&currentIndex, i](const std::string &) { return currentIndex++ != i; });
            if (_check_is_safe(new_values)) {
                total_safe++;
                break;
            }
        }
    }
    std::cout << total_safe << "\n";
}

bool _check_is_safe(const std::vector<std::string> &values) {
    bool is_increasing = false;
    bool is_safe = true;
    for (int i = 0; i < values.size() - 1; i++) {
        int diff = std::stoi(values[i + 1]) - std::stoi(values[i]);
        if (i == 0)
            is_increasing = diff > 0;
        is_safe = _is_safe(diff, is_increasing);
        if (!is_safe)
            break;
    }
    return is_safe;
}

bool _is_safe(int diff, bool is_increasing) {
    if (diff == 0 || std::abs(diff) > 3) {
        return false;
    }
    if (diff < 0 && is_increasing) {
        return false;
    }
    if (diff > 0 && !is_increasing) {
        return false;
    }
    return true;
}
