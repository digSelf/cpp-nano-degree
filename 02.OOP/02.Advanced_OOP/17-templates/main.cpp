#include <iostream>
#include <cassert>

// create a generic function product that multiplies two parameters
// generic code: it is a term for code that is independet of types.

template <typename T>
T multipli(T a, T b) {
    return a * b;
}

int main()
{
    assert(multipli<int>(10, 2) == 20);
    std::cout << "Hello world" << std::endl;
    return 0;
}


