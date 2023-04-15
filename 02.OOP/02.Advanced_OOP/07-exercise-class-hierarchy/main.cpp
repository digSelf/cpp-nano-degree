#include <iostream>
#include <cassert>

class Vehicle {};

class Car : public Vehicle {
public:
    int wheels_{4};
};

class Sedan : public Car {
public:
    bool trunk_{true};
    int seats_{4};
};

int main()
{
    Sedan sedan;
    assert(sedan.trunk_ == true);
    assert(sedan.seats_ == 4);
    assert(sedan.wheels_ == 4);
    std::cout << "Hello world" << std::endl;
    return 0;
}

