// Polimorphism means that "assuming many forms".
// In the context of OOP, poilimorphism describes a paradigm in which a function may behave differently depending
// on how it is called.

// in CPP, you can write two (or more) versions of a function with the same name. This is called "overloading".
// overloading requries that we leave the function name the same, but we modify the function signature.

#include <iostream>

class Human {};
class Dog {};
class Cat {};

// TODO: Write hello() function
void hello() { std::cout << "Hello, World!\n"; }

// TODO: Overload hello() three times
void hello(Human human) { std::cout << "Hello, Human!\n"; }
void hello(Dog dog) { std::cout << "Hello, Dog!\n"; }
void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }

// TODO: Call hello() from main()
int main()
{
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());
}

