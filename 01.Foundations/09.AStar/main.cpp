#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>

// define my own types using enum
enum class State {
    kEmpty = 0,
    kObstacle,
    kClosed
};

std::vector<State> parse_line(std::string line) {
    std::vector<State> result;

    std::istringstream ss(line);
    int x = 0;
    char c = '\0';
    while (ss >> x >> c && c == ',') {
      switch (x) {
      case 0:
        result.push_back(State::kEmpty);
        break;
      case 1:
        result.push_back(State::kObstacle);
        break;
      }
    }
    return result;
}

std::vector<std::vector<State>> read_board_file(std::string path) {
    std::ifstream file(path);
    if (!file) {
        std::cout << "create file stream failed\n";
        return {};
    }

    std::string line;
    std::vector<std::vector<State>> board;
    while (std::getline(file, line)) {
        auto row = parse_line(line);
        board.push_back(row);
    }
    return board;
}

std::string cell_string(State cell) {
    switch (cell) {
        case State::kObstacle:
            return "⛰   ";
        default:
            return "0   ";
    }
}

void print_board(std::vector<std::vector<State>> board) {
    for (auto& line : board) {
        for (State elem : line) {
            std::cout << cell_string(elem);
        }
        std::cout << "\n";
    }
    return;
}
/*
There are several functions need to be implemented:
* cell_sort
* expand_neighbors
* check_valid_cell
* -[x] heuristic
* -[x] add_to_open
* -[x] search
*/

// 02. heuristic
int heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x2 - x1) + std::abs(y2 - y1);
}

// 03. add_to_open
void add_to_open(int x, int y, int g, int h,
                 std::vector<std::vector<int>> &list,
                 std::vector<std::vector<State>> &board) {
    std::vector<int> node = {x, y, g, h};
    board[x][y] = State::kClosed;
    list.push_back(node);
}

bool compare(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    int f1 = lhs[2] + lhs[3];  // g + h
    int f2 = rhs[2] + rhs[3];
    
    return f1 > f2;
}

// 01. search funciton
std::vector<std::vector<State>> search(
    std::vector<std::vector<State>>& board,
    const std::array<int, 2>& start,
    const std::array<int, 2>& goal
) {
    int x = start.front();
    int y = start.back();
    // cost
    int g = 0;
    int h = heuristic(x, y, goal.front(), goal.back());
    
    std::vector<std::vector<int>> list;
    add_to_open(x, y, g, h, list, board);

    std::cout << "no path found\n";
    return {};
}





int main() {
    std::string path = "01.Foundations/09.AStar/1.board";
    auto board = read_board_file(path);
    
    std::array<int, 2> start = {0, 0};
    std::array<int, 2> goal = {4, 5};

    auto solution = search(board, start, goal);
    print_board(solution);
    return 0;
}