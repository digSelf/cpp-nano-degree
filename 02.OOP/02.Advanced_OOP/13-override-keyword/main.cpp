#include <iostream>
#include <cmath>
#include <cassert>

#define PI (3.14159f)

class VehicleModel {
public:
    virtual void move(double x, double t) = 0;
};

class ParticleModel : public VehicleModel {
public:
    void move(double v, double t) override {
        theta_ = theta_ + t;
        x_ = x_ + v * std::cos(theta_);
        y_ = y_ + v * std::cos(theta_);
    }

public:
    double theta_;
    double x_;
    double y_;
};

class BicycleModel : public ParticleModel {
public:
    void move(double v, double t) override {
        theta_ = theta_ + (v / (L * std::tan(t)));

        x_ = x_ + v * std::cos(theta_);
        y_ = y_ + v * std::cos(theta_);
    }

public:
    int L = 1;
};


int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.move(10, PI / 9);
    bicycle.move(10, PI / 9);
    assert(particle.x_ != bicycle.x_);
    assert(particle.y_ != bicycle.y_);
    assert(particle.theta_ != bicycle.theta_);
    std::cout << "Hello world" << std::endl;
    return 0;
}

