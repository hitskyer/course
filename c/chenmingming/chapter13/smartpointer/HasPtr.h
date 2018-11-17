#include"U_Ptr.h"
#ifndef HASPTR_H
#define HASPTR_H
class HasPtr {
public:
    HasPtr(int *p, int i):ptr(new U_Ptr(p)),val(i){ }
    HasPtr(const HasPtr &orig):ptr(orig.ptr),val(orig.val){ ++ptr->use;}
    HasPtr& operator=(const HasPtr&);
    ~HasPtr()
    {
        if(--ptr->use == 0)
            delete ptr;
    }
    int *get_ptr()const
    {
        return ptr->ip;
    }
    int get_int()const
    {
        return val;
    }
    void set_ptr(int *p)
    {
        ptr->ip = p;
    }
    void set_int(int i)
    {
        val = i;
    }
    int get_ptr_val()const
    {
        return *ptr->ip;
    }
    void set_ptr_val(int i)
    {
        *ptr->ip = i;
    }
private:
    U_Ptr *ptr;
    int val;
};
#endif
