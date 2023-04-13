#include <iostream>
#include <string>

class Vehicle {
public:
    int wheels_ = 0;
    std::string color_ = "blue";
    std::string make_ = "generic";

public:
    void print() const {
        std::cout << "This " << color_ << " " << make_ <<  " vehicle has " << wheels_ << " wheels!\n";
    };
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bike : public Vehicle {
public:
    bool kickstand = true;
};

class Scooter : public Vehicle {
public:
    bool electric = false;
};

int main()
{
    Car car;
    Bike bike;
    Scooter scooter;

    car.wheels_ = 4;
    car.print();

    bike.wheels_ = 2;
    bike.print();

    scooter.wheels_ = 2;
    scooter.color_ = "red";
    scooter.print();

    std::cout << "Hello world" << std::endl;
    return 0;
}

