#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<vector<int>> board = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    for (auto& line : board) {
        for (int elem : line) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }

    return 0;
}