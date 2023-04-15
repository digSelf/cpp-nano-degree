#include <iostream>
#include <cassert>

class Point {
public:
    Point() = default;
    Point(int x, int y) : x_(x), y_(y) {}
    
    Point operator + (const Point& rhs) {
        return {this->x_ + rhs.x_, this->y_ + rhs.y_};
    }

public:
    int x_ = 0;
    int y_ = 0;

};

int main()
{
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2;
    assert(p3.x_ == 12);
    assert(p3.y_ == 9);
    std::cout << "Hello world" << std::endl;
    return 0;
}

