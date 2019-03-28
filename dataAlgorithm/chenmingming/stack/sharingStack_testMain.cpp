//
// Created by mingm on 2019/3/28.
//
#include "sharingStack.cpp"
#include <iostream>
using namespace std;
int main()
{
    int L[3] = {0,3,4};
    int len1 = 5, len2;
    for(int k = 0; k < 3; ++k)
    {
        len2 = L[k];
        sharingStack<int> doubleIntStack(8);
        for(int i = 0; i < len1; ++i)
            doubleIntStack.push(i,0);
        for(int i = 0; i < len2; ++i)
            doubleIntStack.push(i,1);
        doubleIntStack.printAll();
    }
    return 0;
}
