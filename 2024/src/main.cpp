#include "aoc.h"
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
        std::cerr << "Invalid useInputFileTxt. Please choose either 0 or 1.\n";
        return 1;
    }
    std::string file_name = AOC::Get_Solution_Test_Case_File_Path(day, use_sample_txt_file == 1);
    std::vector<std::string> *file_contents = AOC::Get_File_Contents(file_name);
    if (!file_contents) {
        std::cerr << "Failed to open the file: " << file_name << std::endl;
        return 1;
    }

    /* Day_01::Solution_02(file_contents); */
    delete file_contents;

    return 0;
}
