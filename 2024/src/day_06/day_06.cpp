#include "day_06.h"

void Day_06::Solution_01(const std::vector<std::string> &input) {
    std::vector<std::string> grid = input;
    const std::size_t row_count = grid.size();
    const std::size_t col_count = grid[0].size();
    Pos pos = {.row = 0, .col = 1};
    // find start pos
    for (std::size_t row = 0; row < row_count; row++) {
        bool found_pos = false;
        for (std::size_t col = 0; col < row_count; col++) {
            if (grid[row][col] != '.' && grid[row][col] != '#') {
                pos.row = row;
                pos.col = col;
                found_pos = true;
                break;
            }
        }
        if (found_pos)
            break;
    }

    // find all unique_pos while traversing through the grid
    char dir = grid[pos.row][pos.col]; // '^', '>', 'v', '<'
    std::size_t unique_pos = 0;
    while (pos.row != -1 && pos.row != row_count && pos.col != -1 && pos.col != col_count) {
        if (grid[pos.row][pos.col] != 'X') {
            grid[pos.row][pos.col] = 'X';
            unique_pos++;
        }
        char next_char;
        if (dir == '^')
            next_char = grid[pos.row - 1][pos.col];
        else if (dir == '>')
            next_char = grid[pos.row][pos.col + 1];
        else if (dir == 'v')
            next_char = grid[pos.row + 1][pos.col];
        else
            next_char = grid[pos.row][pos.col - 1];

        if (next_char == '#') {
            if (dir == '^')
                dir = '>';
            else if (dir == '>')
                dir = 'v';
            else if (dir == 'v')
                dir = '<';
            else
                dir = '^';
        }

        if (dir == '^')
            pos.row--;
        else if (dir == '>')
            pos.col++;
        else if (dir == 'v')
            pos.row++;
        else
            pos.col--;
    }
    std::cout << unique_pos << "\n";
}

/******************************************************************************
 * Part 2
 *
 *****************************************************************************/

void Day_06::Solution_02(const std::vector<std::string> &input) {
    std::vector<std::string> grid = input;
    const std::size_t row_count = grid.size();
    const std::size_t col_count = grid[0].size();
    Pos pos = {.row = 0, .col = 1};
    for (std::size_t row = 0; row < row_count; row++) {
        bool found_pos = false;
        for (std::size_t col = 0; col < col_count; col++) {
            if (grid[row][col] != '.' && grid[row][col] != '#') {
                pos.row = row;
                pos.col = col;
                found_pos = true;
                break;
            }
        }
        if (found_pos)
            break;
    }

    std::size_t num_loops = 0;
    for (std::size_t row = 0; row < row_count; row++) {
        for (std::size_t col = 0; col < col_count; col++) {
            const char temp = grid[row][col];
            if (temp == '#' || temp == '^')
                continue;
            grid[row][col] = '#';
            if (_detect_loop(grid, pos)) {
                num_loops++;
            }
            grid[row][col] = temp;
        }
    }

    std::cout << num_loops << "\n";
}

bool _detect_loop(std::vector<std::string> &grid, const Pos &ar_pos) {
    Pos pos = ar_pos;
    const std::size_t row_count = grid.size();
    const std::size_t col_count = grid[0].size();
    char dir = grid[pos.row][pos.col];
    std::size_t iters = 0;
    while (pos.row != -1 && pos.row != row_count && pos.col != -1 && pos.col != col_count) {
        if (iters++ > row_count * col_count * 4)
            return true;

        char nc;
        if (dir == '^')
            nc = grid[pos.row - 1][pos.col];
        else if (dir == '>')
            nc = grid[pos.row][pos.col + 1];
        else if (dir == 'v')
            nc = grid[pos.row + 1][pos.col];
        else
            nc = grid[pos.row][pos.col - 1];

        if (nc == '#') {
            if (dir == '^')
                dir = '>';
            else if (dir == '>')
                dir = 'v';
            else if (dir == 'v')
                dir = '<';
            else
                dir = '^';
        }

        if (dir == '^')
            pos.row--;
        else if (dir == '>')
            pos.col++;
        else if (dir == 'v')
            pos.row++;
        else
            pos.col--;
    }
    return false;
}
