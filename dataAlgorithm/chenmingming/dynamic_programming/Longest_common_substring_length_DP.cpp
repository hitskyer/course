/**
 * @description: 最长公共子串长度, DP
 * @author: michael ming
 * @date: 2019/7/25 21:40
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
int max(int x, int y, int z)
{
    int m = INT_MIN;
    if(x > m)   m = x;
    if(y > m)   m = y;
    if(z > m)   m = z;
    return m;
}
int lcsDP(string &a, const int lenA, string &b, const int lenB)
{
    int i, j;
    int maxlcs[lenA][lenB];
    for(j = 0; j < lenB; ++j)//初始化第 0 行:a[0..0] 与 b[0..j] 的maxlcs
    {
        if(a[0] == b[j])
            maxlcs[0][j] = 1;
        else if(j != 0)
            maxlcs[0][j] = maxlcs[0][j-1];
        else
            maxlcs[0][j] = 0;
    }
    for(i = 0; i < lenA; ++i)//初始化第 0 列:a[0..i] 与 b[0..0] 的maxlcs
    {
        if(a[i] == b[0])
            maxlcs[i][0] = 1;
        else if(i != 0)
            maxlcs[i][0] = maxlcs[i-1][0];
        else
            maxlcs[i][0] = 0;
    }
    for(i = 1; i < lenA; ++i)//按行填状态表
        for(j = 1; j < lenB; ++j)
        {
            if(a[i] == b[j])
                maxlcs[i][j] = max(maxlcs[i-1][j], maxlcs[i][j-1], maxlcs[i-1][j-1]+1);
            else
                maxlcs[i][j] = max(maxlcs[i-1][j], maxlcs[i][j-1], maxlcs[i-1][j-1]);
        }
    return maxlcs[lenA-1][lenB-1];
}
int main()
{
    string a = "mitcmu", b = "mtacnu";
    cout << "最大公共子串长度：" << lcsDP(a,a.size(),b,b.size()) << endl;
}