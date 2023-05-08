#include <iostream>
#include <thread>

void thread_function() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread thread(thread_function);

    // do something in main
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main" << std::endl;

    // wait for thread to Finish
    thread.join();

    return 0;
}

