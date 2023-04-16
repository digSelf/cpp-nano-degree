#include <iostream>
#include <cassert>
#include <string>

class Animal {
public:
    virtual std::string talk() const = 0;
};

class Dog : public Animal {
public:
    std::string talk() const {
        return std::string("Whoaf");
    }
};

int main()
{
    Dog dog;
    assert(dog.talk() == "Whoaf");
    std::cout << "Hello world" << std::endl;
    return 0;
}

