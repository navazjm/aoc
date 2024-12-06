#include "day_04.h"

void Day_04::Solution_01(const std::vector<std::string> &input) {
    std::size_t row_count = input.size();
    std::size_t col_count = input[0].size();

    int total_xmas = 0;
    for (std::size_t row = 0; row < row_count; row++) {
        for (std::size_t col = 0; col < col_count; col++) {
            if (input[row][col] != 'X')
                continue;

            // diagonal up left
            if (row >= 3 && col >= 3 && _check_diul(input, row, col))
                total_xmas++;
            // up
            if (row >= 3 && _check_u(input, row, col))
                total_xmas++;
            // diagonal up right
            if (row >= 3 && col <= col_count - 3 && _check_diur(input, row, col))
                total_xmas++;
            // right
            if (col <= col_count - 3 && _check_r(input, row, col))
                total_xmas++;
            // diagonal down right
            if (row <= row_count - 3 && col <= col_count - 3 && _check_didr(input, row, col))
                total_xmas++;
            // down
            if (row <= row_count - 3 && _check_d(input, row, col))
                total_xmas++;
            // diagonal down left
            if (row <= row_count - 3 && col >= 3 && _check_didl(input, row, col))
                total_xmas++;
            // left
            if (col >= 3 && _check_l(input, row, col))
                total_xmas++;
        }
    }
    std::cout << total_xmas << "\n";
}

// di -> diagonal
// u -> up
// d -> down
// l -> left
// r -> right
//

// diul -> diagonal up left
bool _check_diul(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row - 1][col - 1] == 'M' && input[row - 2][col - 2] == 'A' && input[row - 3][col - 3] == 'S';
}

// u -> up
bool _check_u(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row - 1][col] == 'M' && input[row - 2][col] == 'A' && input[row - 3][col] == 'S';
}

// diur -> diagonal up right
bool _check_diur(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row - 1][col + 1] == 'M' && input[row - 2][col + 2] == 'A' && input[row - 3][col + 3] == 'S';
}

// r -> right
bool _check_r(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row][col + 1] == 'M' && input[row][col + 2] == 'A' && input[row][col + 3] == 'S';
}

// didr -> diagonal down right
bool _check_didr(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row + 1][col + 1] == 'M' && input[row + 2][col + 2] == 'A' && input[row + 3][col + 3] == 'S';
}

// d -> down
bool _check_d(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row + 1][col] == 'M' && input[row + 2][col] == 'A' && input[row + 3][col] == 'S';
}

// didl -> diagonal down left
bool _check_didl(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row + 1][col - 1] == 'M' && input[row + 2][col - 2] == 'A' && input[row + 3][col - 3] == 'S';
}

// l -> left
bool _check_l(const std::vector<std::string> &input, std::size_t row, std::size_t col) {
    return input[row][col - 1] == 'M' && input[row][col - 2] == 'A' && input[row][col - 3] == 'S';
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_04::Solution_02(const std::vector<std::string> &input) {
    std::size_t row_count = input.size();
    std::size_t col_count = input[0].size();

    int total_xmas = 0;
    for (std::size_t row = 0; row < row_count - 2; row++) {
        for (std::size_t col = 0; col < col_count - 2; col++) {
            // A will ALWAYS be center of 3x3
            if (input[row + 1][col + 1] != 'A')
                continue;
            std::string s1{input[row][col], input[row + 1][col + 1], input[row + 2][col + 2]};
            if (s1 != "MAS" && s1 != "SAM")
                continue;
            std::string s2{input[row][col + 2], input[row + 1][col + 1], input[row + 2][col]};
            if (s2 != "MAS" && s2 != "SAM")
                continue;
            total_xmas++;
        }
    }
    std::cout << total_xmas << "\n";
}
