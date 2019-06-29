/**
 * @description: 贪心算法--区间覆盖应用
 * @author: michael ming
 * @date: 2019/6/29 23:34
 * @modified by: 
 */
#include <iostream>
#include <algorithm>

using namespace std;
struct interval
{
    int left, right;
};
bool comp(interval &a, interval &b)
{
    if(a.left < b.left)
        return true;
    if(a.left = b.left && a.right < b.right)
        return true;
    else
        return false;
}
int main()
{
    interval qujian[6] = {{2,4},{3,5},{5,9},{6,8},{8,10},{1,5}};
    sort(qujian,qujian+5,comp);
    for(int i = 0; i < 5; ++i)
    {

    }
    return 0;
}