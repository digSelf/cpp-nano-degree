#include "processor.h"
#include "linux_parser.h"

#include <string>
#include <vector>
#include <chrono>
#include <thread>

// TODO: Return the aggregate CPU utilization
// https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
/*
        user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
cpu     74608   2520   24433   1117073   6176   4054  0        0      0      0
*/

void get_jiffies(const std::vector<std::string>& cpu_usage, float& total_jiffies, float& work_jiffies) {
    // reset 
    total_jiffies = work_jiffies = 0.0f;
    for (size_t i = 0; i < cpu_usage.size(); ++i) {
        float usage = std::stof(cpu_usage[i]);
        
        // sum up
        if (i < 3) {
            work_jiffies += usage;
        }

        total_jiffies += usage;
    }
}


float Processor::Utilization() { 
    std::vector<std::string> start_cpu_info = LinuxParser::CpuUtilization();
    float prev_total_jiffies, prev_work_jiffies;
    get_jiffies(start_cpu_info, prev_total_jiffies, prev_work_jiffies);

    // wait for a little time to get anoter sampleing
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::vector<std::string> stop_cpu_info = LinuxParser::CpuUtilization();
    float after_total_jiffies, after_work_jiffies;
    get_jiffies(stop_cpu_info, after_total_jiffies, after_work_jiffies);

    float work_load_period = after_work_jiffies - prev_work_jiffies;
    float total_load_period = after_total_jiffies - prev_total_jiffies; 

    float result = work_load_period / total_load_period;
    return result;
}