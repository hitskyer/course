#include "Screen.h"
#include "ScrPtr.h"
#include "ScreenPtr.h"
#include <iostream>
using namespace std;
int main()
{
    Screen scr(3,5,"-*-");
    scr.display(cout);
    ScreenPtr scrp(&scr);
    return 0;
}