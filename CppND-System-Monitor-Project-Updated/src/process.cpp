#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
// https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
float Process::CpuUtilization() { 
    std::vector<std::string> info = LinuxParser::CpuUtilization(pid_);
    int total_time = std::stoi(info[0]) + std::stoi(info[1]);
    // total_time += std::stoi(info[2]) + std::stoi(info[3]);

    long int uptime = UpTime(); 
    int seconds = uptime - (std::stoi(info[4]) / sysconf(_SC_CLK_TCK));
    float result = ((1.0f * total_time) / sysconf(_SC_CLK_TCK)) / seconds;
    return result; 
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    return this->cpu_usage_ > a.cpu_usage_; 
}