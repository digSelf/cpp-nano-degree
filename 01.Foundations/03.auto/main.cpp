#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
    auto i = 5;
    auto v6 = {1, 2, 3};
    cout << "variables declared and initialized without explicitly stating type!\n";

    auto v7 = {4, 5, 6};
    for (auto i : v7) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}