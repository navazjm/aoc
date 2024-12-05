#include "day_03.h"
#include <bits/stdc++.h>

void Day_03::Solution_01(const std::vector<std::string> &input) {
    std::regex mul_pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int result = 0;
    for (const std::string &line : input) {
        auto line_begin = std::sregex_iterator(line.begin(), line.end(), mul_pattern);
        auto line_end = std::sregex_iterator();
        for (std::sregex_iterator it = line_begin; it != line_end; ++it) {
            std::smatch match = *it;
            result += (std::stoi(match[1]) * std::stoi(match[2]));
        }
    }
    std::cout << result << "\n";
}

void Day_03::Solution_02(const std::vector<std::string> &input) {
    std::regex pattern(R"(do\(\)|don't\(\)|mul\(\d{1,3},\d{1,3}\))");
    std::regex mul_pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int result = 0;
    bool is_enabled = true;
    for (const std::string &line : input) {
        auto line_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto line_end = std::sregex_iterator();
        for (std::sregex_iterator it = line_begin; it != line_end; ++it) {
            std::smatch match = *it;
            std::string match_str = match.str();
            if (match_str == "do()") {
                is_enabled = true;
            } else if (match_str == "don't()") {
                is_enabled = false;
            } else {
                std::smatch mul_match;
                if (std::regex_match(match_str, mul_match, mul_pattern)) {
                    if (is_enabled) {
                        result += (std::stoi(mul_match[1]) * std::stoi(mul_match[2]));
                    }
                }
            }
        }
    }
    std::cout << result << "\n";
}
