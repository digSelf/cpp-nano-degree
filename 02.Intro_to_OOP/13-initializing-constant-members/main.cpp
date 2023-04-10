#include <iostream>
#include <cassert>
#include <string>

class Person {
public:
    Person(const std::string& n) : name_(n) {}
    std::string name() const { return name_; }

private:
    std::string const name_;
};

int main()
{
    Person alice("Alice");
    Person bob("Bob");
    assert(bob.name() != alice.name());
    return 0;
}

