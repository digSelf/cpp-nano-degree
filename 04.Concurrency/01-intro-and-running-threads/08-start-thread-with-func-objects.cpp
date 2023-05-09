#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle() = default;

    void operator()() {
        std::cout << "Vehicle object has been created\n";
    }
};

int main()
{
    // There is an error during compilation.
    // The following statement has ambiguity:
    // * a variable definition for variable t of class std::thread, initialized with an anonymous instance of
    // class vehicle.
    // * a function declaration for a fucntion t0 that returns an object of type std::thread and has a single
    // (unnamed) parameter that is a pointer to function returning an object of type Vehicle.
    // std::thread t0(Vehicle());

    // The solutions are shown as follows:
    std::thread t1((Vehicle()));  // add an extra pair of parantheses
    std::thread t2 = std::thread(Vehicle());  // use copy initialization
    std::thread t3 {Vehicle()};  // use uniform initialized with braces.

    // do something in main
    std::cout << "hello world\n";

    // wait for threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

