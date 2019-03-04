//ex14.30 定义一个 CheckedPtr 版本，保存 Screen 数组。
// 为该类 实现重载的自增、自减、解引用、箭头等操作符。
#include "CheckedPtr_Screen.h"
#include "Screen.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Screen *sp = new Screen[8];
    Screen *sp_copy = sp;
    for(int i = 0;i != 8;++i)
    {
        string str = "screen " + to_string(i);
        Screen scr(3,8,str);
        *sp_copy++ = scr;
    }
    CheckedPtr_Screen Cps(sp,sp+8);
    (*Cps).display(cout);
    ++Cps;
    (*Cps).display(cout);
    Cps++;
    (*Cps).display(cout);
    --Cps;
    (*Cps).display(cout);
    Cps--;
    (*Cps).display(cout);
    CheckedPtr_Screen *CPS = &Cps;
    CPS->curr->display(cout);
    delete [] sp;
    CPS = NULL;
    sp_copy = NULL;
    sp = NULL;
    return 0;
}