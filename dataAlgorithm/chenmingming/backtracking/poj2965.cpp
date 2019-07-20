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
bool a[4][4];//存储地图
struct position//位置
{
    int row;
    int column;
};
position posi[30];//位置信息
position finalposi[30];//成功开门的位置信息
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
    {
        a[r][i] = !a[r][i];
        a[i][c] = !a[i][c];
    }
}
void flip(int r, int c,int curstep, long &minstep)
{
    if(isok())
    {
        if(curstep < minstep)
        {
            minstep = curstep;//是一个较短路径
            for(int i = 0; i < curstep; ++i)
            {//较短路径付给最终要输出的路径数组
                finalposi[i].row = posi[i].row;
                finalposi[i].column = posi[i].column;
            }
        }
        return;
    }
    if(r == 4)
        return;
    if(c+1 < 4)//不按这个按钮
        flip(r,c+1,curstep,minstep);
    else if(c+1 == 4)
        flip(r+1,0,curstep,minstep);
    flipAndUpdate(r,c);//按这个按钮
    posi[curstep].row = r;
    posi[curstep].column = c;//记录按钮位置
    curstep++;
    if(c+1 < 4)//按这个按钮
        flip(r,c+1,curstep,minstep);
    else if(c+1 == 4)
        flip(r+1,0,curstep,minstep);
    flipAndUpdate(r,c);//按完了，还要复原
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
    cout << minstep << endl;//输出最短次数
    for(int i = 0; i < minstep; ++i)
    {//输出按按钮的位置信息
        cout << finalposi[i].row+1 << " " << finalposi[i].column+1 << endl;
    }
    return 0;
}