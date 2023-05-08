#ifndef __GC_POINTGER_HPP__
#define __GC_POINTGER_HPP__ 

#include <list>

#include "gc_pointer_details.hpp"

template <typename T, int size=0>
class Pointer {
private:
    // refContainer__ maintains the garbage collection list
    // for each pointer type, it only needs one container.
    static std::list<PtrDetails<T>> refContainer_;
public:
    Pointer() {
        Pointer(nullptr);
    }

    Pointer(T*);
};

// for global and static variables
template <typename T, int size>
std::list<PtrDetails<T>> Pointer<T, size>::refContainer_;

// constructors
template <typename T, int size>
Pointer<T, size>::Pointer(T *ptr) {

}

#endif /* __GC_POINTGER_HPP__ */