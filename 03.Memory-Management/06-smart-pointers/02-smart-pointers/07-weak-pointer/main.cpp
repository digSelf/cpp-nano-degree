#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared(new int);
    std::cout << "shared pointer count = " << shared.use_count() << std::endl;

    std::weak_ptr<int> weak1 = shared;
    std::weak_ptr<int> weak2 = shared;

    std::cout << "shared pointer count = " << shared.use_count() << std::endl;
    return 0;
}

