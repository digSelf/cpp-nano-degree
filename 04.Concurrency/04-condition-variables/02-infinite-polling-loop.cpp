#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>

class Vehicle {
public:
    Vehicle(int id) : id_(id) {}
    int getID() const { return id_; }
private:
    int id_;
};

class WaitingVehicles {
public:
    WaitingVehicles() = default;

    bool dataIsAvailable() {
        std::lock_guard<std::mutex> locker(mutex_);

        return !vehicles_.empty();
    }

    Vehicle popBack() {
        std::lock_guard<std::mutex> locker(mutex_);

        Vehicle v = std::move(vehicles_.back());
        vehicles_.pop_back();
        
        // it will not be copied because of the Return Value Optimization (RVO) technology.
        return v;
    }

    void pushBack(Vehicle&& v) {
        std::lock_guard<std::mutex> locker(mutex_);

        std::cout << "\tVehicle #" << v.getID() << " will be added to the queue\n";
        vehicles_.emplace_back(v);

        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

private:
    std::vector<Vehicle> vehicles_;
    std::mutex mutex_;  // to protect the resource - vehicles_;
};


int main()
{
    std::shared_ptr<WaitingVehicles> queue = std::make_shared<WaitingVehicles>();

    // spawning threads
    std::cout << "Spawning threads ..." << std::endl;
    std::vector<std::future<void>> futrs;

    for (int i = 0; i < 10; ++i) {
        // create a new vehicle instance and move it into the queue
        Vehicle v(i);

        futrs.push_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    while (true) {
        if (queue->dataIsAvailable()) {
            Vehicle v = queue->popBack();
            std::cout << "\tVehicle #" << v.getID() << " has been removed from the queue" << std::endl;
        }
    }
    
    // wait for finishing
    std::for_each(futrs.begin(), futrs.end(), [](std::future<void>& futr){
        futr.wait();
    });

    std::cout << "Finished processing queue" << std::endl;

    return 0;
}

