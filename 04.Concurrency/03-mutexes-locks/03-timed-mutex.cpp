#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include <vector>
#include <memory>
#include <mutex>

class Vehicle {
public:
    Vehicle(int id) : id_(id) {}
    int get_id() const { return id_; }

private:
    int id_;
};

class WaitingVehicles {
public:
    WaitingVehicles() : temp_vehicles_(0) {}

    // getter and setter
    void print_size() {
        // std::cout << "#vehicles = " << temp_vehicles_ << std::endl;
        mutex_.lock();
        std::cout << "#vehicles = " << vehicles_.size() << std::endl;
        mutex_.unlock();
    }

    // typical behavior methods
    void push_back(Vehicle&& v) {
        // mutex_.lock(); 
        for (int i = 0; i < 3; ++i) {
            auto status = mutex_.try_lock_for(std::chrono::milliseconds(50));
            if (status) {
                vehicles_.push_back(std::move(v));  // data race would be cause an execpetion
                mutex_.unlock();

                // remember to break the loop
                break;
            } else {
                std::cout << "Error! #Vehicle = " << v.get_id() << " could not be added to the list" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));  // wait deliberately to expose the data race
            }
        }
    }
private:
    std::vector<Vehicle> vehicles_;
    int temp_vehicles_;
    // std::mutex mutex_;
    std::timed_mutex mutex_;
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

