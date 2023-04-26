#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  
  // open failed.
  if (!filestream.is_open()) {
    return 0.0f;
  }

  std::string line;
  float total_mem = 0.0f;
  float free_mem = 0.0f; 
  while (std::getline(filestream, line)) {
    std::istringstream linestream(line);
    std::string key, value;

    if (linestream >> key >> value) {
      if (key == "MemTotal:") {
        total_mem = std::stof(value);
      } else if (key == "MemFree:") {
        free_mem = std::stof(value);
      }
    }
  }

  float used_mem = total_mem - free_mem;
  float result = used_mem / total_mem;
  return result; 
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (!stream.is_open()) {
    return 0;
  }

  std::string line;
  std::getline(stream, line);

  std::istringstream linestream(line);
  long value = 0;
  linestream >> value;

  return value;
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
  // sampling
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (!filestream.is_open()) {
    return {};
  }

  // if open success
  std::string line;
  if (!std::getline(filestream, line)) {
    return {};
  }

  // if get line success
  std::vector<std::string> result;
  std::istringstream linestream(line);

  std::string cpu;
  linestream >> cpu;

  std::string component;
  while (linestream >> component) {
    result.emplace_back(component);
  }

  return result; 
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (!stream.is_open()) {
    return 0;
  }

  std::string line;
  int result = 0;
  while (std::getline(stream, line)) {
    std::string key, value;
    std::istringstream linestream(line);
    if (linestream >> key >> value) {
      if (key == "processes") {
        result = std::stoi(value);
        break;
      }
    }
  }

  return result;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (!stream.is_open()) {
    return 0;
  }

  std::string line;
  int result = 0;
  while (std::getline(stream, line)) {
    std::string key, value;
    std::istringstream linestream(line);
    if (linestream >> key >> value) {
      if (key == "procs_running") {
        result = std::stoi(value);
        break;
      }
    }
  }

  return result;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  if (!stream.is_open()) {
    return {};
  }

  std::string line;
  std::getline(stream, line);

  return line; 
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (!stream.is_open()) {
    return {};
  }

  std::string line;
  while (std::getline(stream, line)) {
    std::string key, value;
    std::istringstream linestream(line);
    if (linestream >> key >> value) {
      if (key == "VmSize:") {
        int temp = int((1.0f * std::stoi(value)) / 1024);
        return std::to_string(temp);
      }
    }
  }

  return {};
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (!stream.is_open()) {
    return {};
  }

  std::string line;
  std::string value;
  std::string key;
  while (std::getline(stream, line)) {
    std::istringstream linestream(line);
    if (linestream >> key >> value) {
      if (key == "Uid:") {
        return value;
      }
    }
  }

  return {};
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  std::string uid = LinuxParser::Uid(pid);

  std::ifstream stream(kPasswordPath);
  if (!stream.is_open()) {
    return {};
  }

  std::string line;
  while (std::getline(stream, line)) {
    std::replace(line.begin(), line.end(), ':', ' ');
    std::string name, passwd, uid_;
    std::istringstream linestream(line);
    if (linestream >> name >> passwd >> uid_) {
      if (uid_ == uid) {
        return name;
      }
    }
  }

  return {};
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (!stream.is_open()) {
    return 0;
  }

  std::string line;
  if (!std::getline(stream, line)) {
    return 0;
  }

  std::istringstream linestream(line);
  std::string value;
  int n = 1;
  while (linestream >> value) {
    if (n == 22) {
      // return (1.0f * std::stol(value)) / sysconf(_SC_CLK_TCK);
      return std::stol(value);
    }
    ++n;
  }

  return 0; 
}

vector<string> LinuxParser::CpuUtilization(int pid) {
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (!stream.is_open()) {
    return {};
  }

  std::string line;
  if (!std::getline(stream, line)) {
    return {};
  }

  std::istringstream linestream(line);
  int i = 1; 
  std::string value;
  std::vector<std::string> result;
  while (linestream >> value) {
    if (i == 14 || i == 15 || i == 16 || i == 17 || i == 22) {
      result.emplace_back(value);
    }
    i++;
  }
  return result;
}
