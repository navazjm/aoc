#include "day_05.h"
#include "../aoc.h"

void Day_05::Solution_01(const std::vector<std::string> &input) {
    std::unordered_map<std::string, std::vector<std::string>> order;
    int total_middle_pages = 0;

    for (const std::string &line : input) {
        // get before|after page ordering
        if (line.size() == 5) {
            std::vector<std::string> values = AOC::Split(line, '|');
            order[values[0]].push_back(values[1]);
            continue;
        }
        // skip empty line in txt file
        if (line.size() == 0) {
            continue;
        }
        // check if update is in correct order
        std::unordered_set<std::string> seen;
        std::vector<std::string> values = AOC::Split(line, ',');
        bool is_correct_order = true;
        for (const std::string &val : values) {
            std::vector<std::string> after = order[val];
            for (const std::string &af : after) {
                if (seen.count(af)) {
                    is_correct_order = false;
                    break;
                }
            }
            if (!is_correct_order)
                break;
            seen.insert(val);
        }
        if (is_correct_order)
            total_middle_pages += std::stoi(values[values.size() / 2]);
    }
    std::cout << "Day 5 Part 1: " << total_middle_pages << "\n";
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_05::Solution_02(const std::vector<std::string> &input) {
    std::unordered_map<std::string, std::vector<std::string>> order;
    int total_middle_pages = 0;

    for (const std::string &line : input) {
        // get before|after page ordering
        if (line.size() == 5) {
            std::vector<std::string> values = AOC::Split(line, '|');
            order[values[0]].push_back(values[1]);
            continue;
        }
        // skip empty line in txt file
        if (line.size() == 0) {
            continue;
        }
        std::vector<std::string> values = AOC::Split(line, ',');
        std::size_t iters = 0;
        while (true) {
            iters++;
            std::vector<std::size_t> indices_to_move = _incorrect_order(values, order);
            if (indices_to_move.size() == 0)
                break;
            std::size_t curr_idx = indices_to_move[0];
            std::string val = values[curr_idx];
            values.erase(values.begin() + curr_idx);
            std::size_t new_idx = indices_to_move[1];
            values.insert(values.begin() + new_idx, val);
        }

        if (iters > 1)
            total_middle_pages += std::stoi(values[values.size() / 2]);
    }
    std::cout << "Day 5 Part 2: " << total_middle_pages << "\n";
}

/**
 * @returns Empty vector if values in the correct order based on order parameter. Otherwise,
 * returns the {current index, new index to move to}
 */
std::vector<std::size_t> _incorrect_order(const std::vector<std::string> &values,
                                          std::unordered_map<std::string, std::vector<std::string>> order) {
    std::unordered_map<std::string, std::size_t> seen;
    for (std::size_t i = 0; i < values.size(); i++) {
        const std::string &val = values[i];
        std::vector<std::string> after = order[val];
        for (const std::string &af : after) {
            if (seen.find(af) != seen.end()) {
                return {i, seen[af]};
            }
        }
        seen.insert({val, i});
    }
    return {};
}
