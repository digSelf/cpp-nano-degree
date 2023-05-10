#include <iostream>
#include <thread>
#include <future>
#include <string>

// each promise object are used only a single time
void modify_message(std::promise<std::string>&& prms, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::string modifed_msg = message + " has been modifed";
    
    // use set_value to set the value into the promise object.
    // the sending end called "promise"
    prms.set_value(modifed_msg);
}

int main()
{
    // define message
    std::string msg = "Main Message";

    // create promise and future
    std::promise<std::string> prms;
    // a future object is stored in the object of promise
    std::future<std::string> futr = prms.get_future();
    
    std::thread t(modify_message, std::move(prms), msg);

    // print original message to console
    std::cout << msg << std::endl;
    
    // retrieve modifed message via future and print to console
    std::string msg_from_thread = futr.get();
    std::cout << "modifed message: " << msg_from_thread << std::endl;

    t.join();
    return 0;
}

