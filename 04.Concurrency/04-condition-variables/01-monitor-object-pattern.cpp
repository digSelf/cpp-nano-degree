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

    void printIDs() {
        std::lock_guard<std::mutex> locker(mutex_);

        for (auto& v : vehicles_) {
            std::cout << "\tVehicle #" << v.getID() << " is now waiting in the queue\n";
        }
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
    
    // wait for finishing
    std::for_each(futrs.begin(), futrs.end(), [](std::future<void>& futr){
        futr.wait();
    });

    std::cout << "Collecting result ...\n";
    queue->printIDs();

    return 0;
}

