#include <iostream>
#include <string>


// define a base class
class Animal {
public:
    void make_sound(std::string sound) {
        std::cout << age_ << "-year-old" << " " << color_ << " " 
            << name_ << " make a " <<  sound << std::endl;
    }
public:
    std::string color_;
    std::string name_;
    int age_;
};

// define a derived class
class Snake : public Animal {
public:
    float length_;
};

class Cat : public Animal {
public:
    float height_;
};

int main()
{
    Snake snake;
    snake.age_ = 2;
    snake.color_ = "blue";
    snake.name_ = "Kuchy";
    snake.length_ = 20;
    snake.make_sound("sisi");
    
    Cat cat;
    cat.age_ = 1;
    cat.color_ = "white";
    cat.name_ = "Tom";
    cat.height_ = 20;
    cat.make_sound("miao");

    return 0;
}

