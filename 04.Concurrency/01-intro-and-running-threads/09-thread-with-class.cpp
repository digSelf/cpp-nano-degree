#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle(int id) : id_(id) {}

    // must overload the function operator
    void operator()() {
        std::cout << "Vehicle #" << id_ << " has been created\n";
    }

private:
    int id_;
};

int main()
{
    // create thread
    // use copy constructor
    std::thread t = std::thread(Vehicle(1));

    std::cout << "Hello world" << std::endl;

    // wait for the thread to finish
    t.join();

    return 0;
}

