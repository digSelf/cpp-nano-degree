#include <iostream>
#include <cassert>
#include <cmath>

class Sphere {
public:
    static float volume(int radius) {
        return 4.0 / 3 * pi_ * std::pow(radius, 3);
    }
private:
    constexpr static float pi_ = 3.14159f;
};

int main()
{
    assert(std::abs(Sphere::volume(5) - 523.6) < 1);
    std::cout << "Hello world" << std::endl;
    return 0;
}

