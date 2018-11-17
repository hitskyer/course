#include "Value_HasPtr.h"
Value_HasPtr& Value_HasPtr::operator=(const Value_HasPtr &rhs)
{
    *ptr = *rhs.ptr;
    val = rhs.val;
    return *this;
}
