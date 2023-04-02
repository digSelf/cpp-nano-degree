#include <iostream>
#include <sstream>  // string stream
#include <string>

int main() {
    std::string s = "a b c 1 2 3";

    // ">>" is called "extraction operator"
    // the operator will read the first non-whitespace character 
    // or the input string stream failed.
    std::istringstream stream(s);
    char n;
    while (stream >> n) {
        std::cout << n;
    }
    std::cout << "\n";
    return 0;
}