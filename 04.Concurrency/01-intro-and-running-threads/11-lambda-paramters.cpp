#include <iostream>

int main()
{
    int id = 0;

    auto f = [](const int id){ std::cout << "ID = " << id << std::endl; };

    f(id);
    std::cout << "Hello world" << std::endl;
    return 0;
}

