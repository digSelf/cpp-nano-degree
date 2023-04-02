#include <iostream>
#include <fstream>  // file stream header
#include <string>

void read_board_file(std::string path) {
    // ifstream == input file stream
    std::ifstream file(path);
    if (!file) {
        std::cout << "creating input file stream failed.\n";
        return;
    }

    // read each line in the file with `getline` function.
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    return;
}

int main() {
    std::string path = "01.Foundations/05.read_file/1.board";
    read_board_file(path);
    return 0;
}