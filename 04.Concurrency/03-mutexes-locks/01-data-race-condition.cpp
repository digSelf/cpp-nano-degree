#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include <vector>
#include <memory>

class Vehicle {
public:
    Vehicle(int id) : id_(id) {}

private:
    int id_;
};

class WaitingVehicles {
public:
    WaitingVehicles() : temp_vehicles_(0) {}

    // getter and setter
    void print_size() {
        std::cout << "#vehicles = " << temp_vehicles_ << std::endl;
    }

    // typical behavior methods
    void push_back(Vehicle&& v) {
        // vehicles_.push_back(std::move(v));  // data race would be cause an execpetion
        int old_num = temp_vehicles_;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // wait deliberately to expose the data race
        temp_vehicles_ += 1;
    }
private:
    std::vector<Vehicle> vehicles_;
    int temp_vehicles_;
};

int main()
{
    std::shared_ptr<WaitingVehicles> queue = std::make_shared<WaitingVehicles>();
    std::vector<std::future<void>> futrs;

    for (int i = 0; i < 1000; ++i) {
        futrs.emplace_back(std::async(std::launch::async, &WaitingVehicles::push_back, queue, std::move(Vehicle(i))));
    }
    
    std::for_each(futrs.begin(), futrs.end(), [](std::future<void>& ftr){
                    ftr.wait();
                  });

    queue->print_size();
    return 0;
}

