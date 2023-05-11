#include <chrono>
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cmath>

void worker(int n) {
    // print system id of worker thread
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

    // perform work
    for (int i = 0; i < n; ++i)
    {
        sqrt(12345.6789);
    }
}

int main()
{
    // print system id
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    // start time measurement
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // launch various tasks
    std::vector<std::future<void>> futures;
    double loop_times = 10, thread_num = 5;
    for (int i = 0; i < thread_num; ++i) {
        futures.emplace_back(std::async(std::launch::deferred, worker, loop_times));
    }

    // wait for result
    for (int i = 0; i < thread_num; ++i) {
        futures[i].wait();
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // get result
    auto result = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Execution finished after " << result << " microseconds\n";
    return 0;
}

