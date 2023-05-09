#include <iostream>

int main()
{
    // create lambda
    int id = 0;  // define an integer variable

    // error: id could not be accessed in the body of a lambda
    // auto f0 = [](){ std::cout << "ID =" << id << std::endl; };
    
    id++;
    // [capture list](parameter list) {body};
    // capture by value
    auto f1 = [id](){ std::cout << "ID = " << id << std::endl; };
    
    id++;
    // capture by reference
    auto f2 = [&id](){ std::cout << "ID = " << id << std::endl; };

    id++;
    // the integer variable id may be modified.
    auto f3 = [id]() mutable { std::cout << "ID = " << id <<std::endl; };

    f1();
    f2();
    f3();


    std::cout << "Hello world" << std::endl;
    return 0;
}

