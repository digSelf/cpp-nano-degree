#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <future>
#include <vector>

std::mutex g_mutex;
double g_result;

void print_result(int denom) {
    std::cout << "for denom = " << denom << ", the result is " << g_result << std::endl;
} 

void divide_by_number(double num, double denom) {
    try {
        if (denom != 0) {
            std::lock_guard<std::mutex> locker(g_mutex);
            g_result = num / denom;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            print_result(denom);
        } else {
            throw std::invalid_argument("Exception from thread: Division By 0!");
        }
    } catch (const std::invalid_argument& e) {
        // notify the user about the exception and return
        std::cout << e.what() << std::endl;
        return;
    }
}

int main()
{
    std::vector<std::future<void>> futrs;
    double num = 42.0;
    for (int i = -5; i < 5; ++i) {
        futrs.emplace_back(std::async(std::launch::async, divide_by_number, num, i));
    }

    for (auto& f : futrs) {
        f.wait();
    }
    return 0;
}

