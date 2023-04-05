#include <iostream>
#include <string>
using std::cout;

int main() {
    // what are "types" in C++
    // it is the definition of a variable. The variable can be used if and only if
    // you give a defintion of the variable.
    // 1. Declaring and initializing an int variable
    int a = 10;

    // 2. Declaring a string variable without initializing right away.
    std::string s;
    // 3. assigning a string to the variable s.
    s = "here is a string";

    cout << "a=" << a << ", s=" << s << "\n";
    return 0;
}