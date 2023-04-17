#include <iostream>
#include <cassert>

template <typename T>
T average(T a, T b) {
    return (a + b) / 2;
}

int main()
{
    assert(average(2.0, 5.0) == 3.5);
    std::cout << "Hello world" << std::endl;
    return 0;
}

