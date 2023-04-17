#include <iostream>
#include <cassert>

template <typename T>
T max(T a, T b) {
    return (a > b ? a : b);
}

int main()
{
    assert(max<int>(10, 20) == 20);
    assert(max<double>(3.14, 2.236) == 3.14);
    std::cout << "Hello world" << std::endl;
    return 0;
}

