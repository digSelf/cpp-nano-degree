#include <chrono>
#include <iostream>


int main()
{
    const int size = 4;
    static int x[size][size];

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // debug version: 98 ms 
            // x[j][i] = i + j;
            
            // debug version: 43 ms
            x[i][j] = i + j;
            std::cout << &x[i][j] << ": i=" << i << ", j=" << j << std::endl;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    // format time spending result
    long cost = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout << "Execution time: " << cost << " microseconds" << std::endl;

    return 0;
}

