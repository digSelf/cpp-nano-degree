#include <iostream>
#include <cassert> 
#include <sstream>
#include <string>

template <typename KeyType, typename ValueType>
class Mapping {
public:
    Mapping(KeyType key, ValueType value) : key_(key), value_(value) {}

    std::string print() const {
        std::ostringstream stream;
        stream << key_ << ": " << value_;
        return stream.str();
    }

public:
    KeyType key_;
    ValueType value_;
};


int main()
{
    Mapping<std::string, int> mapping("age", 20);
    assert(mapping.print() == "age: 20");
    std::cout << "Hello world" << std::endl;
    return 0;
}

