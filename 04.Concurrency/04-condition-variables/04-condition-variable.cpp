#include <condition_variable>
#include <iostream>
#include <memory>
#include <vector>
#include <future>
#include <mutex>
#include <thread>
#include <algorithm>

template <typename T>
class MessageQueue {
public:
    MessageQueue() = default;

    T receive() {
        std::unique_lock<std::mutex> ulocker(mutex_);
        // while (!pred())  
        //   wait();
        cond_.wait(ulocker, [this](){  return !messages_.empty(); });

        // hold locker automatically
        T msg = std::move(messages_.back());
        messages_.pop_back();

        // it will not be copied because of RVO in C++
        return msg;
    }

    void send(T&& msg) {
        // simulte work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> locker(mutex_);

        std::cout << "\tMessage " << msg << " has been sent to the queue" << std::endl;
        messages_.emplace_back(msg);
        cond_.notify_one();
    }

private:
    std::vector<T> messages_;
    std::mutex mutex_;
    std::condition_variable cond_;
};


int main()
{
    std::shared_ptr<MessageQueue<int>> queue = std::make_shared<MessageQueue<int>>();

    std::cout << "Spawning threads ...\n";
    std::vector<std::future<void>> futrs;

    for (int i = 0; i < 10; ++i) {
        int message = i;
        futrs.push_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }

    std::cout << "Collecting results ...\n";
    while (true) {
        int msg = queue->receive();
        std::cout << "\tMessage #" << msg << " has been removed from the queue" << std::endl;
    }
    
    std::for_each(futrs.begin(), futrs.end(), [](std::future<void>& f){ f.wait(); });

    std::cout << "Finished!\n";
    return 0;
}

