#include "day_09.h"
#include <iterator>

void Day_09::Solution_01(const std::vector<std::string> &input) {
    // build disk map from input
    std::string sequence = input[0];
    int id = 0;
    std::vector<int> disk_map;
    for (std::size_t i = 0; i < sequence.size(); i++) {
        int count = static_cast<int>(sequence[i]) - '0';
        int n = i % 2 == 0 ? id++ : -1;
        while (count-- > 0) {
            disk_map.push_back(n);
        }
    }

    // swap free space
    for (std::size_t i = disk_map.size() - 1; i >= 0; i--) {
        int n = disk_map[i];
        if (n == -1)
            continue;
        auto it = std::find(disk_map.begin(), disk_map.end(), -1);
        if (it == disk_map.end())
            break;
        int idx = std::distance(disk_map.begin(), it);
        if (idx >= i)
            break;
        disk_map[idx] = n;
        disk_map[i] = -1;
    }

    ll check_sum = 0;
    for (std::size_t i = 0; i < disk_map.size(); i++) {
        if (disk_map[i] == -1)
            continue;
        int n = disk_map[i];
        check_sum += (n * i);
    }

    std::cout << check_sum << "\n";
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_09::Solution_02(const std::vector<std::string> &input) {
    // build disk map from input
    std::string sequence = input[0];
    int id = 0;
    std::vector<int> disk_map;
    for (std::size_t i = 0; i < sequence.size(); i++) {
        int count = static_cast<int>(sequence[i]) - '0';
        int n = i % 2 == 0 ? id++ : -1;
        while (count-- > 0) {
            disk_map.push_back(n);
        }
    }

    // swap free space
    int cn = disk_map[disk_map.size() - 1];
    std::size_t cs = 1;
    int i = disk_map.size() - 2;
    while (cn == -1 && i >= 0)
        cn = disk_map[i--];
    while (i >= 0) {
        int n = disk_map[i];
        if (n == cn) {
            cs++;
            i--;
            continue;
        }

        // find first occurence of -1
        auto it = std::find(disk_map.begin(), disk_map.end(), -1);
        if (it == disk_map.end())
            break;

        std::size_t fi = std::distance(disk_map.begin(), it);
        std::size_t cfi = fi;
        while (cfi < i) {
            if (disk_map[cfi] == -1) {
                cfi++;
                continue;
            }
            if (cfi - fi >= cs)
                break;

            auto it = std::find(disk_map.begin() + cfi, disk_map.end(), -1);
            if (it == disk_map.end())
                break;
            fi = std::distance(disk_map.begin(), it);
            cfi = fi + 1;
        }

        if (cfi - fi >= cs) {
            for (std::size_t j = 0; j < cs; j++) {
                disk_map[fi + j] = cn;
                disk_map[i + j + 1] = -1;
            }
        }
        cn = n;
        cs = 1;
        i--;
        while (cn == -1 && i >= 0)
            cn = disk_map[i--];
    }

    ll check_sum = 0;
    for (std::size_t i = 0; i < disk_map.size(); i++) {
        if (disk_map[i] == -1)
            continue;
        int n = disk_map[i];
        check_sum += (n * i);
    }

    std::cout << check_sum << "\n6221662795602\n";
}
