#include "HasPtr.h"
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++rhs.ptr->use;
    if(--ptr->use == 0)
        delete ptr;
    ptr = rhs.ptr;
    val = rhs.val;
    return *this;
}
