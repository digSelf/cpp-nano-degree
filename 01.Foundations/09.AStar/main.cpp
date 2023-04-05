#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include <algorithm>

// define my own types using enum
enum class State {
    kEmpty = 0,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
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
        case State::kStart:
            return "🚦   ";
        case State::kFinish:
            return "🏁   ";
        case State::kPath:
            return "🚗   ";
        default:
            return " 0   ";
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
                 std::vector<std::vector<int>> &frontier,
                 std::vector<std::vector<State>> &board) {
    std::vector<int> node = {x, y, g, h};
    board[x][y] = State::kClosed;
    frontier.push_back(node);
}

bool compare(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    int f1 = lhs[2] + lhs[3];  // g + h
    int f2 = rhs[2] + rhs[3];
    
    return f1 > f2;
}

void cell_sort(std::vector<std::vector<int>>& frontier) {
    std::sort(frontier.begin(), frontier.end(), compare);
}

bool equal_node(int x, int y, const std::array<int, 2>& rhs) {
    int rhs_x = rhs[0];
    int rhs_y = rhs[1];

    return (x == rhs_x) && (y == rhs_y);
}

bool check_valid_cell(int x, int y, const std::vector<std::vector<State>>& board) {
    // check if the coordinate pair is on the grid.
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
        return false;
    }

    // check if the grid at (x,y) is closed or obstacle.
    if (board[x][y] != State::kEmpty) {
        return false;
    }

    return true;
}

void expand_neighbors(
    std::vector<int>& current, 
    std::vector<std::vector<int>>& frontier,
    std::vector<std::vector<State>>& board,
    const std::array<int, 2>& goal
) {
    // directions array
    const int delta[][2] = {
        {-1, 0},  // left
        {0, -1},  // up
        {1, 0},   // right
        {0, 1}    // down
    };

    int x = current[0];
    int y = current[1];
    for (auto& cor : delta) {
        if (!check_valid_cell(x + cor[0], y + cor[1], board)) {
            continue;
        }

        // increase g, compute h, add neighbor to the frontier
        int g = current[2] + 1;
        int h = heuristic(x + cor[0], y + cor[1], goal[0], goal[1]);

        add_to_open(x + cor[0], y + cor[1], g, h, frontier, board);
    }
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

    // board[x][y] = State::kStart;
    // board[goal.front()][goal.back()] = State::kFinish;
    
    std::vector<std::vector<int>> frontier;
    add_to_open(x, y, g, h, frontier, board);

    while (!frontier.empty()) {
        cell_sort(frontier);
        auto current = frontier.back(); frontier.pop_back();
        int x = current[0];
        int y = current[1];
        board[x][y] = State::kPath;

        // Check if you've reached the goal. If so, return grid.
        if (equal_node(x, y, goal)) {
            return board;
        }

        expand_neighbors(current, frontier, board, goal);
    }

    std::cout << "no path found\n";
    return {};
}

int main() {
    std::string path = "01.Foundations/09.AStar/1.board";
    auto board = read_board_file(path);
    
    std::array<int, 2> start = {0, 0};
    std::array<int, 2> goal = {4, 5};

    auto solution = search(board, start, goal);
    solution[start.front()][start.back()] = State::kStart;
    solution[goal.front()][goal.back()] = State::kFinish;
    print_board(solution);
    return 0;
}