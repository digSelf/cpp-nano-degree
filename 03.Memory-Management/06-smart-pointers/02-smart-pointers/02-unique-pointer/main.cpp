#include <memory>  // smart pointers

void raw_pointer() {
    int *raw = new int;  // create a raw pointer on the heap
    *raw = 1;   // assign a value
    delete raw;  // delete the resource again
}

void unique_pointer() {
    // format: auto ptr = std::unique_ptr<object_type>(new object_type)
    // the smart pointer must create on the stack
    auto ptr = std::unique_ptr<int>(new int);
    *ptr = 1;
}

int main() {
    raw_pointer();
    unique_pointer();
    return 0;
}
