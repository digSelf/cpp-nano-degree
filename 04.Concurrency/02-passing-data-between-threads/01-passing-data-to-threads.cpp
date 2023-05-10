#include <iostream>
#include <thread>
#include <string>

void printMessage(std::string msg) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Thread 1: " << msg << std::endl;
}

int main()
{
    // define message
    std::string message = "My Message";

    // start thread using variadic templates
    std::thread t1(printMessage, message);

    // start thread using a lambda
    std::thread t2([message](){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Thread 2: " << message << std::endl;
        
    });

    t1.join();
    t2.join();

    std::cout << "Hello world" << std::endl;
    return 0;
}

