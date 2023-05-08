#include <iostream>
#include <ratio>
#include <thread>

void thread_function() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
    std::cout << "finished work 1 in thread\n";

    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
    std::cout << "finished work 2 in thread\n";
}

int main()
{
    // create thread
    std::thread t(thread_function);

    // do something in main
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "finished work 2 in main\n";

    // wait for thread to finish
    t.join();
    return 0;
}


