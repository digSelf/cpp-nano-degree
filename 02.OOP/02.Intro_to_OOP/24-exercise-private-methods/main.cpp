#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cmath>

class Sphere {
public:
    Sphere(int r) : radius_(r), volume_(4.0 / 3 * pi_ * std::pow(r, 3)) {
       validate(r); 
    }

    // accessor
    int radius() const { return radius_; }
    float volume() const { return volume_; }

    // mutator
    void radius(int r);

private:
    void validate(int r);
private:
    const float pi_ = 3.14159f;
    int radius_;
    float volume_;
};

void Sphere::validate(int r) {
    if (r <= 0) {
        throw std::invalid_argument("radius is negative");
    }
}

void Sphere::radius(int r) {
    validate(r);    

    radius_ = r;
    volume_ = 4.0 / 3 * pi_ * std::pow(r, 3);
}

int main()
{
    Sphere sphere(5);
    assert(sphere.radius() == 5);
    assert(std::abs(sphere.volume() - 523.6) < 1);

    sphere.radius(3);
    assert(sphere.radius() == 3);
    assert(std::abs(sphere.volume() - 113.1) < 1);

    bool caught{false};
    try
    {
        sphere.radius(-1);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);

    std::cout << "Hello world" << std::endl;
    return 0;
}
