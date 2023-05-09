#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    int id = 0;

    // starting a first thread (by reference)
    auto f0 = [&id]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "a) ID in thread (call-by-reference) = " << id << std::endl;
    };

    std::thread t0(f0);

    // starting a second thread (by value)
    auto f1 = [id]() mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "b) ID in thread (call-by-value) = " << id << std::endl;
    };

    id++;
    std::thread t1(f1);

    std::cout << "Hello world" << std::endl;

    t0.join();
    t1.join();

    return 0;
}

