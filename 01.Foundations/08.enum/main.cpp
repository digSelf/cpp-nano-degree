#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// define my own types using enum
enum class State {
    kEmpty = 0,
    kObstacle
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

int main() {
    std::string path = "01.Foundations/08.enum/1.board";
    auto board = read_board_file(path);
    print_board(board);
    return 0;
}