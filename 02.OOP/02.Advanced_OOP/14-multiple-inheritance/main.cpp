#include <iostream>
#include <string>
#include <cassert>

// "Use multiple inheritance to represent multiple distinct interfaces"
// "Use multiple inheritance to represent the union of implementation attributes"

class Animal {
public:
    double age_;
};

class Pet {
public:
    std::string name_;
};

class Dog : public Animal, public Pet {
public:
    std::string breed_;
};

class Cat : public Animal, public Pet {
public:
    std::string color_;
};

int main()
{
    Cat cat;
    cat.color_ = "black";
    cat.age_ = 10;
    cat.name_ = "Smith";

    assert(cat.color_ == "black");
    assert(cat.age_ == 10);
    assert(cat.name_ == "Smith");
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

