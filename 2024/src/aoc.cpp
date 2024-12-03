#include "aoc.h"
#include <optional>

std::vector<std::string> AOC::Split(const std::string &str, const char delimiter) {

    std::istringstream iss(str);
    std::vector<std::string> tokens;

    std::string token;
    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::optional<std::vector<std::string>> AOC::Get_File_Contents(const std::string &file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        return std::nullopt;
    }

    std::vector<std::string> file_contents;
    std::string line;
    while (std::getline(file, line)) {
        file_contents.push_back(line);
    }
    file.close();

    return file_contents;
}

std::string AOC::Get_Solution_Test_Case_File_Path(int day, bool use_sample_txt_file) {
    std::string filePath = std::string("./src/day_") + (day < 10 ? "0" : "") + std::to_string(day);

    if (use_sample_txt_file) {
        return filePath + "/sample.txt";
    }

    return filePath + "/input.txt";
}
