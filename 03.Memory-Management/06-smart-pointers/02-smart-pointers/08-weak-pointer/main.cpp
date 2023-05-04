#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared(new int);
    std::weak_ptr<int> weak = shared;
    
    // shared.reset(new int);
    shared.reset();

    // check whether a weak pointer to a resource is valid
    if (weak.expired() == true) {
        std::cout << "weak pointer expired!" << std::endl;
    }
    return 0;
}

