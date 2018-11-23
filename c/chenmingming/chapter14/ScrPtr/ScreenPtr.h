#include"Screen.h"
#include "ScrPtr.h"
#ifndef SCRPTR_SCREENPTR_H
#define SCRPTR_SCREENPTR_H


class ScreenPtr
{
public:
    ScreenPtr(Screen *p):ptr(new ScrPtr(p)){ }
    ScreenPtr(const ScreenPtr &orig):ptr(orig.ptr){++ptr->use;}
    ScreenPtr& operator=(const ScreenPtr&);
    bool friend operator==(const ScreenPtr &s1,const ScreenPtr &s2)
    {
        return s1.ptr == s2.ptr;
    }
    bool friend operator!=(const ScreenPtr &s1,const ScreenPtr &s2)
    {
        return !(s1==s2);
    }
    ~ScreenPtr()
    {
        if(--ptr->use == 0)
            delete ptr;
    }
private:
    ScrPtr *ptr;
};


#endif
