#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared_pointer(new int);
    std::cout << "shared pointer count = " << shared_pointer.use_count() << std::endl;

    {
        std::shared_ptr<int> shared_pointer2 = shared_pointer;
        std::cout << "shared pointer count = " << shared_pointer.use_count() << std::endl;
    }

    std::cout << "shared pointer count = " << shared_pointer.use_count() << std::endl;

    return 0;
}

