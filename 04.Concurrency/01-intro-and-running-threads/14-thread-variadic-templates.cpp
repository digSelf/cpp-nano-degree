#include <chrono>
#include <iostream>
#include <thread>
#include <string>

void printID(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    std::cout << "ID = " << id <<", name = " << name << std::endl;
}

int main()
{
    int id = 0;

    // start threadsd using variadic templates
    std::thread t1(printID, id);
    std::thread t2(printIDAndName, ++id, "MyString");

    std::cout << "Hello world" << std::endl;

    // wait for threads before returning
    t1.join();
    t2.join();

    return 0;
}

