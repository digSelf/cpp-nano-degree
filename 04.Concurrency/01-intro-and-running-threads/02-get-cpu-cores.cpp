#include <iostream>
#include <thread>

int main()
{
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "this machine supports concurrency with " << cores << " cores available" << std::endl;
    return 0;
}

