#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> parse_line(std::string line) {
    std::vector<int> result;

    std::istringstream ss(line);
    int x = 0;
    char c = '\0';
    while (ss >> x >> c) {
        result.push_back(x);
    }
    return result;
}

std::vector<std::vector<int>> read_board_file(std::string path) {
    std::ifstream file(path);
    if (!file) {
        std::cout << "create file stream failed\n";
        return {};
    }

    std::string line;
    std::vector<std::vector<int>> board;
    while (std::getline(file, line)) {
        auto row = parse_line(line);
        board.push_back(row);
    }
    return board;
}

void print_board(std::vector<std::vector<int>> board) {
    for (auto& line : board) {
        for (int elem : line) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
    return;
}

int main() {
    std::string path = "01.Foundations/07.parseline/1.board";
    auto board = read_board_file(path);
    print_board(board);
    return 0;
}