#ifndef CHECKEDPTR_SCREEN_CHECKEDPTR_SCREEN_H
#define CHECKEDPTR_SCREEN_CHECKEDPTR_SCREEN_H
#include "Screen.h"
using namespace std;
class Screen;
class CheckedPtr_Screen
{
public:

    CheckedPtr_Screen(Screen *b,Screen *e):beg(b),end(e),curr(b){ }
    //解引用操作
    Screen& operator*();
    const Screen& operator*()const;
    //自增和自减操作
    //前缀式
    CheckedPtr_Screen& operator++();
    CheckedPtr_Screen& operator--();
    //后缀式
    CheckedPtr_Screen operator++(int);
    CheckedPtr_Screen operator--(int);
    //箭头操作符
    Screen* operator->();
    const Screen* operator->()const;
    Screen *curr;
private:
    Screen *beg,*end;
};
#endif
