/**
 * @description: 
 * @author: michael ming
 * @date: 2019/7/11 22:09
 * @modified by: 
 */
#include <iostream>
#include <string>
using namespace std;
bool a[4][4];
bool isok()//判断是否都是同种颜色
{
    int i, j;
    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            if(a[i][j] != a[0][0])
            {
                return false;
            }
        }
    }
    return true;
}
void flipAndUpdate(int r, int c)//翻转r，c处及其周围棋子
{
    a[r][c] = !a[r][c];
    if(r-1 >= 0)
        a[r-1][c] = !a[r-1][c];
    if(r+1 < 4)
        a[r+1][c] = !a[r+1][c];
    if(c-1 >= 0)
        a[r][c-1] = !a[r][c-1];
    if(c+1 < 4)
        a[r][c+1] = !a[r][c+1];
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
            if(s[j] == 'b')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    flip(0,0,0,minstep);
    if(minstep == 65536)
        cout << "Impossible" << endl;
    else
        cout << minstep;
    return 0;
}