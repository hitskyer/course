/**
 * @description: dp 状态表法
 * @author: michael ming
 * @date: 2019/7/19 23:30
 * @modified by: 
 */
#include <iostream>
#include <stack>
#define N 4//地图大小
using namespace std;
void printShortestWay(int (*map)[N], int (*states)[N])
{
    stack<int> path;
    path.push(map[N-1][N-1]);//终点
    for(int i = N-1,j = N-1; j != 0 && i != 0; )
    {
        if(states[i][j]-map[i][j] == states[i-1][j])
            path.push(map[--i][j]);//从上面过来的
        else
            path.push(map[i][--j]);//从左边过来的
    }
    path.push(map[0][0]);//起点
    cout << "走过的点的距离分别是：" << endl;
    while(!path.empty())//栈逆序弹出路径
    {
        cout << path.top() << " ";
        path.pop();
    }
}
void step_dp(int (*map)[N])
{
    int (*states)[N] = new int [N][N];
    int i, j, sum = 0;
    for(j = 0; j < N; ++j)//初始化第一行状态
    {
        sum += map[0][j];
        states[0][j] = sum;
    }
    sum = 0;
    for(i = 0; i < N; ++i)//初始化第一列状态
    {
        sum += map[i][0];
        states[i][0] = sum;
    }
    for(i = 1; i < N; ++i)//填写状态表
        for(j = 1; j < N; ++j)
            states[i][j] = map[i][j]+min(states[i][j-1],states[i-1][j]);
    cout << "最短路径是：" << states[N-1][N-1] << endl;
    printShortestWay(map,states);
    delete [] states;
    return;
}
int main()
{
    int map[N][N] = {1,3,5,9,2,1,3,4,5,2,6,7,6,8,4,3};
    step_dp(map);
    return 0;
}