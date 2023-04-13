#include <iostream>
#include <cassert>
#include <stdexcept>

class Pyramid {
public:
    Pyramid(int l, int w, int h) : length_(l), width_(w), height_(h) {
        validate();
    }

    // accessors
    int length() const { return length_; }
    int width() const { return width_; }
    int height() const { return height_; }

    int volume() const { return (length_ * width_ * height_) / 3; }

    // mutators
    void length(int l);
    void width(int w);
    void height(int h);
    
private:
    void validate();

private:
    int length_;
    int width_;
    int height_;
};

void Pyramid::validate() {
    if (length_ < 0 || width_ < 0 || height_ < 0) {
        std::__throw_invalid_argument("negative values");
    }
}

void Pyramid::height(int h) {
    if (h >= 0) {
        height_ = h;
    }
}

void Pyramid::width(int w) {
    if (w >= 0)
        width_ = w;
}

void Pyramid::length(int l) {
    if (l >= 0) {
        length_ = l;
    }
}

int main()
{
    Pyramid pyramid(4, 5, 6);
    assert(pyramid.length() == 4);
    assert(pyramid.width() == 5);
    assert(pyramid.height() == 6);
    assert(pyramid.volume() == 40);

    bool caught{false};
    try
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch (...)
    {
        std::cout << "Entered negative values"
                  << "\n";
        caught = true;
    }
    assert(caught);
    return 0;
}

