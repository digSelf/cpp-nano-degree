#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>

class Sphere {
public:
    Sphere(int r) : radius_(r), volume_(4.0 / 3 * pi_ * std::pow(radius_, 3)) {
        if (r < 0.0) {
            throw std::invalid_argument("radius is negative");
        }
    }

    // accessors
    float volume() const { return volume_; }
    int radius() const { return radius_; }

private:
    float volume_;
    int radius_;
    constexpr static float pi_ = 3.14159f;
};

int main()
{
    Sphere sphere(5);
    assert(sphere.radius() == 5);
    assert(abs(sphere.volume() - 523.6) < 1.0);

    return 0;
}

