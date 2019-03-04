#include <iostream>
#include "CheckedPtr.h"
using namespace std;
int main()
{
    int ia[10] = {1,2,3,4,5,6,7,8,9,10};
    CheckedPtr parr(ia,ia+10),parr1(ia,ia+10);
    parr.operator++(0);
    parr.operator++();
    parr[3];
    parr++;
    ++parr;
    *parr;
    parr != parr1;
    parr >= parr1;
    parr-parr1;
    parr1 = parr + 1;
    return 0;
}