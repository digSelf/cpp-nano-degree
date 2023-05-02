#include <iostream>

// Note: each expression in cpp has a type and belongs to a value category.
int main()
{
    // initialize some variables on the stack.
    int i, j, *p;

    // i is an lvaue and 42 is an rvalue.
    i = 42;

    p = new int;

    // the dereferenced pointer is an lvalue
    *p = i;
    delete p;

    // the conditional operator returns an lvalue (either i or j)
    ((i < 42) ? i : j) = 23;
    
    return 0;
}

