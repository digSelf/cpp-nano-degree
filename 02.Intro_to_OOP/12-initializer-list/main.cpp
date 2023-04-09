#include <iostream>
#include <cassert>
#include <string>

class Person {
public:
    Person(std::string n) : name_(n) {}
    std::string name() const { return name_; }

private:
    std::string name_;
};

int main()
{
    Person alice("Alice");
    std::cout << alice.name() << std::endl;

    return 0;
}

