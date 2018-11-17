#ifndef U_PTR_H
#define U_PTR_H
#include <cstring>
class U_Ptr
{
    friend class HasPtr;
    int *ip;
    size_t use;
    U_Ptr(int *p):ip(p),use(1){ }
    ~U_Ptr(){ delete ip;}
};
#endif
