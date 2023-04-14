#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cassert>

#define PI (3.14159f)

class LineSegment {
public:
    float length_;
};

class Circle {
public:
    Circle(const LineSegment& r) : radius_(r) {
        if (r.length_ < 0) {
            throw std::invalid_argument("raidus is negative");
        }
    }

    float area() const {
        return std::pow(radius_.length_, 2) * PI;
    }
private:
    LineSegment radius_;
};

int main()
{
    LineSegment radius {3};
    try {
        Circle circle {radius};
        assert(std::fabs(28.28 - circle.area()) < 1.0);
    } catch (...) {
        std::cout << "radius is negative\n";
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

