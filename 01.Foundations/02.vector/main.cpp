#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
    // three ways of declaring and intializing vectors;
    vector<int> v1{0, 1, 2};
    vector<int> v2 = {3, 4, 5};
    vector<int> v3;
    v3 = {6};

    cout << "everything worked! \n";

    // creating a 2D vector
    vector<vector<int>> v4 {
        {1, 2},
        {3, 4}
    };
    cout << "Great! A 2D vector has been created.\n";

    return 0;
}