#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_mutex1, g_mutex2;

void ThreadA() {
    // crate deadlock problem
    std::lock_guard<std::mutex> locker2(g_mutex2);
    std::cout << "Thread A" << std::endl;
    std::lock_guard<std::mutex> locker1(g_mutex1);
}

void ThreadB() {
    // crate deadlock problem
    std::lock_guard<std::mutex> locker1(g_mutex1);
    std::cout << "Thread B" << std::endl;
    std::lock_guard<std::mutex> locker2(g_mutex2);
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

