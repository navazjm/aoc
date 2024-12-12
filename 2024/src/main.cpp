#include "aoc.h"
#include "day_01/day_01.h"
#include "day_02/day_02.h"
#include "day_03/day_03.h"
#include "day_04/day_04.h"
#include "day_05/day_05.h"
#include "day_06/day_06.h"
#include "day_07/day_07.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: <day (1-25)> <part (1/2)> <input or sample data (0/1)>\n";
        return 1;
    }
    int day = std::atoi(argv[1]);
    if (day < 1 || day > 25) {
        std::cerr << "Invalid day. Please choose a number in the range 1-25.\n";
        return 1;
    }

    int part = std::atoi(argv[2]);
    if (part != 1 && part != 2) {
        std::cerr << "Invalid part. Please choose either 1 or 2.\n";
        return 1;
    }

    int use_sample_txt_file = 0;
    if (argv[3]) {
        use_sample_txt_file = std::atoi(argv[3]);
    }
    if (use_sample_txt_file != 0 && use_sample_txt_file != 1) {
        std::cerr << "Invalid value for determing if using sample.txt. Please choose either 0 or 1.\n";
        return 1;
    }
    std::string file_name = AOC::Get_Solution_Test_Case_File_Path(day, use_sample_txt_file == 1);
    auto file_contents = AOC::Get_File_Contents(file_name);
    if (!file_contents.has_value()) {
        std::cerr << "Failed to open the file: " << file_name << std::endl;
        return 1;
    }

    switch (day) {
    case 1:
        if (part == 2)
            Day_01::Solution_02(file_contents.value());
        else
            Day_01::Solution_01(file_contents.value());
        break;
    case 2:
        if (part == 2)
            Day_02::Solution_02(file_contents.value());
        else
            Day_02::Solution_01(file_contents.value());
        break;
    case 3:
        if (part == 2)
            Day_03::Solution_02(file_contents.value());
        else
            Day_03::Solution_01(file_contents.value());
        break;
    case 4:
        if (part == 2)
            Day_04::Solution_02(file_contents.value());
        else
            Day_04::Solution_01(file_contents.value());
        break;
    case 5:
        if (part == 2)
            Day_05::Solution_02(file_contents.value());
        else
            Day_05::Solution_01(file_contents.value());
        break;
    case 6:
        if (part == 2)
            Day_06::Solution_02(file_contents.value());
        else
            Day_06::Solution_01(file_contents.value());
        break;
    case 7:
        if (part == 2)
            Day_07::Solution_02(file_contents.value());
        else
            Day_07::Solution_01(file_contents.value());
        break;
    default:
        std::cout << "Could not find solution to Day " << day << " Part " << part << ".\n";
    }

    return 0;
}
