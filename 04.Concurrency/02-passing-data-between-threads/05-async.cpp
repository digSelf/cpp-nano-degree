#include <iostream>
#include <stdexcept>
#include <thread>
#include <cmath>
#include <future>

double divide_by_number(double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    if (denom == 0.0) {
        throw std::runtime_error("Exception from thread: Division by zero!");
    }

    return num / denom;
}

int main()
{
    // use async to start a task
    double num = 42.0, denom = 0.0;
    std::future<double> futr = std::async(divide_by_number, num, denom);

    // retrieve result within try-catch-block
    try {
        double result = futr.get();
        std::cout << "Result: " << result << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

