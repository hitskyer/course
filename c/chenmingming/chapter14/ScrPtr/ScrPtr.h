#include"Screen.h"
#ifndef SCRPTR_SCRPTR_H
#define SCRPTR_SCRPTR_H
class Screen;
class ScrPtr
{
    friend class ScreenPtr;
    Screen *sp;
    size_t use;
    ScrPtr(Screen *p):sp(p),use(1){ }
    ~ScrPtr(){delete sp;}
};
#endif
