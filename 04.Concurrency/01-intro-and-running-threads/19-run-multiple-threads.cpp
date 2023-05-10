#include <iostream>
#include <thread>
#include <vector>

void printHello() {
    // perform work
    std::cout << "Hello from worker thread #" << std::this_thread::get_id() << std::endl;
}

int main()
{
    // create threads
    std::vector<std::thread> threads;
    
    // a thread object could be copied because it does not have a copy constructor
    for (size_t i = 0; i < 5; ++i) {
        threads.emplace_back(std::thread(printHello));
    }

    // do something in main
    std::cout << "Hello world" << std::endl;

    // wait for join
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

