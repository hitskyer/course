/**
 * @description: 改造的杨辉三角，从顶层下来的最小和
 * @author: michael ming
 * @date: 2019/7/17 23:03
 * @modified by: 
 */
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int high = 5;
int YHTriangle[high][high] = {{5},{7,8},{2,1,4},{4,2,6,1},{2,7,3,4,5}};

void shortestPath()
{
    int states[high][high];//存放路径距离（存较小的）
//    memset(states,65535,high*high*sizeof(int));
    states[0][0] = YHTriangle[0][0];//第一个点的距离
    int i, j;
    for(i = 1; i < high; ++i)//动态规划
    {
        for(j = 0; j <= i; ++j)
        {
            if(j == 0)//在两边，上一个状态没得选，只有一个
                states[i][j] = states[i-1][j]+YHTriangle[i][j];
            else if(j == i)//在两边，上一个状态没得选，只有一个
                states[i][j] = states[i-1][j-1]+YHTriangle[i][j];
            else//在中间，上一个状态有两个，选路径短的
                states[i][j] = min(states[i-1][j],states[i-1][j-1])+YHTriangle[i][j];
        }
    }
    int mins = 65535, idx;
    for(j = 0; j < high; ++j)
    {
        if(mins > states[high-1][j])
        {
            mins = states[high-1][j];//选出最短的
            idx = j;//记录最短的路径位置
        }
    }
    cout << "最短的路径是：" << mins << endl;
    //-----------打印路径-----------------------
    cout << "从底向上走过的点的值是：" << endl;
    cout << YHTriangle[high-1][idx] << " ";
    for(i = high-1,j = idx; i > 0; --i)
    {
        if(j == 0)
            cout << YHTriangle[i-1][j] << " ";
        else if(j == i)
        {
            cout << YHTriangle[i-1][j-1] << " ";
            j--;
        }
        else
        {
            if(states[i-1][j-1] < states[i-1][j])
            {
                cout << YHTriangle[i-1][j-1] << " ";
                j--;
            }
            else
                cout << YHTriangle[i-1][j] << " ";
        }
    }
}
int main()
{
    shortestPath();
    return 0;
}