#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    long hh = seconds / 3600;
    long mm = (seconds % 3600) / 60;
    long ss = seconds - hh * 3600 - mm * 60;

    std::ostringstream hhs, mms, sss;
    hhs << std::setw(2) << std::setfill('0') << hh;
    mms << std::setw(2) << std::setfill('0') << mm;
    sss << std::setw(2) << std::setfill('0') << ss;

    std::string result = hhs.str() + ':' + mms.str() + ':' + sss.str();

    return result; 
}