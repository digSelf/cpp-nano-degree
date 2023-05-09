#include <iostream>
#include <thread>
#include <string>

void printName(std::string& name, int waitTime) {
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from thread)";
    std::cout << name << std::endl;
}

int main()
{
    std::string name = "MyThread";

    std::thread t(printName, std::ref(name), 50);

    std::cout << "Hello world" << std::endl;

    t.join();
    name += " (from main)";
    std::cout << name << std::endl;
    return 0;
}

