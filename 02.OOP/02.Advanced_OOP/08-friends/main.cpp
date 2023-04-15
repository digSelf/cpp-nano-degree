#include <iostream>
#include <cassert>

// the friend keyword grants access to the private membors of a class.

class Rectangle;

class Square {
public:
    Square(int s) : side_(s) {}

private:
    friend class Rectangle;
    int side_;
};

class Rectangle {
public:
    Rectangle(const Square& sq) : width_(sq.side_), height_(sq.side_) {}

    int area() const { return width_ * height_; }

private:
    int width_ = 0;
    int height_ = 0;
};

int main()
{
    Square sq {4};
    Rectangle rect {sq};
    std::cout << rect.area() << std::endl;
    return 0;
}

