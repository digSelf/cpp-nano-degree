#include <chrono>
#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void compute_sqrt(std::promise<double>&& prms, double input) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    double output = std::sqrt(input);
    prms.set_value(output);
}

int main()
{
    // define input data
    double input_data = 36.0;
    
    // create promise and corresponding future 
    std::promise<double> prms;
    std::future<double> futr = prms.get_future();

    // start thread
    std::thread t(compute_sqrt, std::move(prms), input_data);

    // wait for result to become avaiable
    auto status = futr.wait_for(std::chrono::seconds(1));
    if (status == std::future_status::ready) {
        // if user performs the get operation in future, it will not valid anymore.
        double result = futr.get();
        std::cout << "result: " << result << std::endl;
    }
    else if (status == std::future_status::timeout || status == std::future_status::deferred) {
        std::cout << "result unavalable" << std::endl;
    }

    t.join();
    return 0;
}

