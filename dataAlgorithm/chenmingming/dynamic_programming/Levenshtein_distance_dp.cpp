/**
 * @description: 莱文斯坦距离，动态规划
 * @author: michael ming
 * @date: 2019/7/25 20:40
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
int min(int x, int y, int z)
{
    int m = INT_MAX;
    if(x < m)   m = x;
    if(y < m)   m = y;
    if(z < m)   m = z;
    return m;
}
int lwstDP(string &a, const int lenA, string &b, const int lenB)
{
    int i, j;
    int minDist[lenA][lenB];
    for(j = 0; j < lenB; ++j)//初始化第 0 行:a[0..0] 与 b[0..j] 的编辑距离
    {
        if(a[0] == b[j])
            minDist[0][j] = j;
        else if(j != 0)
            minDist[0][j] = minDist[0][j-1]+1;
        else
            minDist[0][j] = 1;
    }
    for(i = 0; i < lenA; ++i)//初始化第 0 列:a[0..i] 与 b[0..0] 的编辑距离
    {
        if(a[i] == b[0])
            minDist[i][0] = i;
        else if(i != 0)
            minDist[i][0] = minDist[i-1][0]+1;
        else
            minDist[i][0] = 1;
    }
    for(i = 1; i < lenA; ++i)//按行填状态表
        for(j = 1; j < lenB; ++j)
        {
            if(a[i] == b[j])
                minDist[i][j] = min(minDist[i-1][j]+1, minDist[i][j-1]+1, minDist[i-1][j-1]);
            else
                minDist[i][j] = min(minDist[i-1][j]+1, minDist[i][j-1]+1, minDist[i-1][j-1]+1);
        }
    return minDist[lenA-1][lenB-1];
}
int main()
{
    string a = "mitcmu", b = "mtacnu";
    cout << "莱文斯坦距离：" << lwstDP(a,a.size(),b,b.size()) << endl;
}