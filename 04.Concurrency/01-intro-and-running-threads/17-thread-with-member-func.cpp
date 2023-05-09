#include <iostream>
#include <thread>

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
    Vehicle v1, v2;

    std::thread t1 = std::thread(&Vehicle::addID, v1, 1);
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2);

    t1.join();
    t2.join();

    v1.printID();
    v2.printID();

    return 0;
}

