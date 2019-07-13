/**
 * @description: poj1321回溯
 * @author: michael ming
 * @date: 2019/7/13 13:58
 * @modified by: 
 */

#include <iostream>
#include <string>
using namespace std;

bool a[10][10];
int result[10];
bool isok(int r, int c)//判断是否都是同种颜色
{
    for(int i = r - 1; i >= 0; --i)//逐行向上考察每一行
    {
        if(result[i] == c)//第i行的c列有棋子吗
            return false;
    }
    return true;
}

void flip(int r, int num, int &count, int n, int k)
{
    if(num == k)    //k个棋子都放置好了，打印结果
    {
        count++;
        return;//都放置好了，没法再递归了
    }
    if(r == n)
        return;//边界，没法再递归了
    for(int column = 0; column < n; ++column)//每行有n种放法
    {
        if(a[r][column] != 1)
            continue;
        if(column == n - 1 && a[r][column] != 1)
        {
            column = 0;
            r = r + 1;
        }
        if(isok(r,column))    //该放法满足要求
        {
            result[r] = column;//第r行的棋子放到了column列
            num++;
            flip(r+1, num, count, n, k);  //考察下一行
            result[r] = -1;
            num--;
        }
    }
    flip(r+1, num, count, n, k);  //第r行不放棋子，考察下一行
}
int main()
{
    string s;
    int i, j, n, k, num = 0, count;
    while(cin >> n >> k && n != -1)
    {
        count = 0;
        for (i = 0; i < n; ++i)
        {
            cin >> s;
            for (j = 0; j < n; ++j)
            {
                if (s[j] == '#')
                    a[i][j] = 1;//1的地方才可以放棋子
                else
                    a[i][j] = 0;
            }
        }
        flip(0, num, count, n, k);
        cout << count << endl;
    }
    return 0;
}