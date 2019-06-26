/**
 * @description: 给定系列长度，求是否有规定的三角形
 *              （不是所有的都可以组成三角形&&有至少一种组合可以组成三角形）
 *              考察输入putchar()比较快，按位输入
 * @author: michael ming
 * @date: 2019/5/20 22:38
 * @modified by: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int num[1000001];
char ch;
int input()
{
    int res = 0;
    while(ch = getchar())
    {
        if(ch >= '0' && ch <= '9')
            res = res*10 + ch - '0';
        else
            break;
    }
    return res;
}
bool check(int *num, int n)
{
    if(n <= 3)
        return false;
    if(num[0]+num[1] > num[n-1])    //全部可以组成三角形
        return false;
    for(int i = 0; i < n-2; i++)
    {
        if(num[i]+num[i+1] > num[i+2])  //有至少一种三角形可能
            return true;
    }
    return false;
}
int main()
{
    int n;
    n = input();
    for (int i = 0; i < n; ++i)
        num[i] = input();
    sort(num, num+n);
    if (check(num, n))
        printf("The set is accepted.\n");
    else
        printf("The set is rejected.\n");
    return 0;
}