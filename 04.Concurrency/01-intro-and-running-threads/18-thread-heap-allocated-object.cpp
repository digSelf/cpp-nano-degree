#include <iostream>
#include <thread>
#include <memory>

class Vehicle {
public:
    Vehicle() = default;

    void addID(int id) { id_ += id; }
    void printID() {
        std::cout << "Vehicle ID = " << id_ << std::endl;
    }

private:
    int id_ = 0;
};

int main()
{
    // create thread
    std::shared_ptr<Vehicle> v = std::make_shared<Vehicle>();

    std::thread t1 = std::thread(&Vehicle::addID, v, 1);

    // do not forget to wait for the thread 
    t1.join();

    v->printID();

    return 0;
}

