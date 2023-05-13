#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_mutex1, g_mutex2;

void ThreadA() {
    // crate deadlock problem
    // require mutexes at the same time
    // Ensure that locks are always executed in the same order
    // regardless of the order of the arguments to call the std::lock function
    std::lock(g_mutex1, g_mutex2);
    // the `std::adopt_lock` option allows use to use a std::lock_guard on a locked `mutex`
    std::lock_guard<std::mutex> locker2(g_mutex2, std::adopt_lock);

    std::cout << "Thread A" << std::endl;
    std::lock_guard<std::mutex> locker1(g_mutex1, std::adopt_lock);
}

void ThreadB() {
    // crate deadlock problem
    std::lock(g_mutex2, g_mutex1);
    std::lock_guard<std::mutex> locker1(g_mutex1, std::adopt_lock);
    std::cout << "Thread B" << std::endl;
    std::lock_guard<std::mutex> locker2(g_mutex2, std::adopt_lock);
}

int main()
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);

    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;
    return 0;
}

