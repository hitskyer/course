#include <iostream>
#include "median.h"
using namespace std;
int main()
{
    int ia1[] = {1,2,3,4,5,6,7};
    int ia2[] = {1,2,3,4};
    int ia3[] = {1,2,2,3,4,5,6};
    vector<int> ivec1(ia1,ia1+7);
    vector<int> ivec2(ia2,ia1+4);
    vector<int> ivec3(ia3,ia3+7);
    int m;
    if(median(ivec1,m))
        cout << "median: " << m << endl;
    else
        cout << "no median" << endl;
    if(median(ivec2,m))
        cout << "median: " << m << endl;
    else
        cout << "no median" << endl;
    if(median(ivec3,m))
        cout << "median: " << m << endl;
    else
        cout << "no median" << endl;
    return 0;
}