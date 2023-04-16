#include <iostream>
#include <cmath>

class Shape {
public:
    virtual float area() const = 0;
};

class Circle : public Shape {
public:
    Circle(int r) : radius_(r) {}
    float area() const {
        return std::pow(radius_, 2) * pi_;
    }

private:
    int radius_;
    constexpr static float pi_ = 3.14159f;
};

int main()
{
    Circle circle{2};
    std::cout << "circle area: " << circle.area() << std::endl;
    return 0;
}

