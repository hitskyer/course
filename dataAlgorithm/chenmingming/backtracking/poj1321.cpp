/**
 * @description: poj1321回溯
 * @author: michael ming
 * @date: 2019/7/13 13:58
 * @modified by: 
 */
#include <iostream>
#include <string>
using namespace std;

bool a[10][10];//存储棋盘
int result[10];//存储是否存放棋子（和8皇后类似）
bool isok(int r, int c)//判断是否可以摆放
{
    for(int i = r - 1; i >= 0; --i)//逐行向上考察每一行
    {
        if(result[i] == c)//上面所有行的c列有棋子吗
            return false;
    }
    return true;
}

void flip(int r, int num, int &count, int n, int k)
{
    if(num == k)    //k个棋子都放置好了
    {
        count++;    //记录可行方案数
        return;//都放置好了，没法再递归了
    }
    if(r == n)
        return;//边界，没法再递归了
    for(int column = 0; column < n; ++column)//r行可能有n种放法
    {
        if(a[r][column] != 1)
            continue;//寻找可放置的位置
        if(isok(r,column))    //该放法满足要求
        {
            result[r] = column;//第r行的棋子放到了column列
            num++;//放置棋子数加1
            flip(r+1, num, count, n, k);  //放了棋子 考察下一行
            result[r] = -1;//恢复现场，这个地方不放棋子，找下一种方法
            num--;//放置的棋子数减1
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
        count = 0;//计数清零
        for (i = 0; i < n; ++i)//输入地图
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