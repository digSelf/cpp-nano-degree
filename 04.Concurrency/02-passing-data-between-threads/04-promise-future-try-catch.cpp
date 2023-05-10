#include <exception>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

void divide_by_number(std::promise<double>&& prms, double num, double deno) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    try {
        if (deno == 0.0) {
            throw std::runtime_error("divide by 0");
        } else {
            prms.set_value(num / deno);
        }
    } catch (...) {
        prms.set_exception(std::current_exception());
    }
}

int main()
{
    std::promise<double> prms;
    std::future<double> futr = prms.get_future();

    double num = 13.0, deno = 0.0;
    std::thread t(divide_by_number, std::move(prms), num, deno);

    // retrieve result within try-catch-block
    try {
        auto value = futr.get();
        std::cout << "result = " << value << std::endl;

    } catch (std::runtime_error e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    t.join();

    return 0;
}

