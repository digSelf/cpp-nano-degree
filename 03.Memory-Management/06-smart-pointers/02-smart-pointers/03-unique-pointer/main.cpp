#include <iostream>
#include <memory>
#include <string>

class MyClass {
private:
    std::string text_;

public:
    MyClass() = default;
    MyClass(std::string text) : text_(text) {}

    ~MyClass() { std::cout << text_ << " destroyed " << std::endl; }
    
    void set_text(std::string text) { text_ = text; }
};

int main()
{
    // create unique pointer to properietary calss
    std::unique_ptr<MyClass> myclass1(new MyClass());
    std::unique_ptr<MyClass> myclass2(new MyClass("string 2"));

    // call member function using ->
    myclass1->set_text("string 1");

    // use the dereference operator *
    *myclass1 = *myclass2;

    // use the .get() function to retrieve a raw pointer to the object
    std::cout << "Objects have stack addresses " << myclass1.get() << " and " << myclass2.get() << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

