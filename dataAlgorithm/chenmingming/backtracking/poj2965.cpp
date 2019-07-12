/**
 * @description: 回溯算法求解
 * @author: michael ming
 * @date: 2019/7/12 23:08
 * @modified by: 
 */
#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool a[4][4];
queue<pair<int,int> > posqueue;
bool isok()//判断是否都是-号（0）
{
    int i, j;
    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            if(a[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
void flipAndUpdate(int r, int c)//翻转r，c处及其所在行和列
{
    a[r][c] = !a[r][c];
    for(int i = 0; i < 4; ++i)
        a[r][i] = !a[r][i];
    for(int i = 0; i < 4; ++i)
        a[i][c] = !a[i][c];
}
void flip(int r, int c,int curstep, long &minstep)
{
    if(isok())
    {
        if(curstep < minstep)
            minstep = curstep;
        return;
    }
    if(c+1 < 4)
        flip(r,c+1,curstep,minstep);
    else if(c+1 == 4 && r+1 < 4)
        flip(r+1,0,curstep,minstep);
    flipAndUpdate(r,c);
    posqueue.push(make_pair(r,c));
    curstep++;
    if(c+1 < 4)
        flip(r,c+1,curstep,minstep);
    else if(c+1 == 4 && r+1 < 4)
        flip(r+1,0,curstep,minstep);
    flipAndUpdate(r,c);//翻完了，还要复原？
}
int main()
{
    string s;
    int i, j;
    long minstep = 65536;
    for(i = 0; i < 4; ++i)
    {
        cin >> s;
        for(j = 0; j < 4; ++j)
        {
            if(s[j] == '-')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    flip(0,0,0,minstep);
    cout << minstep;
    return 0;
}