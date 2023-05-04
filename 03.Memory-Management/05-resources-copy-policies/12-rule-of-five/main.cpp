#include <cstdlib>
#include <iostream>

class MyMovableClass {
private:
    int size_;
    int *data_;

public:
    // 1. constructor
    MyMovableClass(size_t size) {
        size_ = size;
        data_ = new int[size];
        std::cout << "creating instance of MyMovableClass at " << this << " allocated with size = " \
            << size_ * sizeof(int) << " bytes" << std::endl;
    }

    // 2. destructor
    ~MyMovableClass() {
        if (data_) {
            delete[] data_;
            data_ = nullptr;
        }

        size_ = 0;
        std::cout << "deleting instance of MyMovableClass at " << this << std::endl;
    }

    // 3. copy constructor
    MyMovableClass(const MyMovableClass& other) {
        size_ = other.size_; 

        data_ = new int[size_];
        *data_ = *other.data_;
        
        std::cout << "copy content of instance " << &other << " to instance " << this << std::endl;
    }

    // 4. assignment operator
    MyMovableClass& operator=(const MyMovableClass& other) {
        std::cout << "assigning content of instance " << &other << " to instance " << this << std::endl;

        if (this == &other) {
            return *this;
        }

        if (data_) {
            delete[] data_;
            size_ = 0;
        }

        size_ = other.size_;
        data_ = new int[size_];

        *data_ = *other.data_;

        return *this;
    }

    // 5. move constructor
    MyMovableClass(MyMovableClass&& other) {
        std::cout << "moving (c'tor) instance " << &other << " to instance " << this << std::endl;

        data_ = other.data_;
        size_ = other.size_;
        
        other.size_ = 0;
        other.data_ = nullptr;
    }
    // 6. move assignment operator
    MyMovableClass& operator=(MyMovableClass&& other) {
        if (this == &other) {
            return *this;
        }

        if (data_) {
            delete[] data_;
            size_ = 0;
        }

        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;

        return *this;
    }
};

int main() {
    // constructor 
    MyMovableClass obj1(100);

    // move assignment
    obj1 = MyMovableClass(200);

    // move constructor
    MyMovableClass obj2 = MyMovableClass(300);

    return 0;
}
