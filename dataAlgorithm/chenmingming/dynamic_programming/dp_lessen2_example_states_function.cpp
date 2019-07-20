/**
 * @description: dp 状态方程 递归
 * @author: michael ming
 * @date: 2019/7/20 9:35
 * @modified by: 
 */
#include <iostream>
#include <stack>
#define N 4//地图大小
using namespace std;
int states [N][N];
void printShortestWay(int (*map)[N])
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
int minDist(int (*map)[N], int i, int j)//从起点到i,j点的最小距离
{
    if(i == 0 && j == 0)//从起点到起点，返回该位置数值
        return map[0][0];
    if(states[i][j] > 0)//遇到算过的，直接返回结果
        return states[i][j];
    int minLeft, minUp;
    minLeft = minUp = 65535;
    if(j-1 >= 0)
        minLeft = minDist(map,i,j-1);//点左边的点的最小距离
    if(i-1 >= 0)
        minUp = minDist(map,i-1,j);//点上面的点的最小距离
    int currMinDist = map[i][j]+min(minLeft,minUp);
    states[i][j] = currMinDist;//备忘录更新
    return currMinDist;
}
int main()
{
    int map[N][N] = {1,3,5,9,2,1,3,4,5,2,6,7,6,8,4,3};
    cout << "最短路径是：" << minDist(map,N-1,N-1) << endl;
    printShortestWay(map);
    return 0;
}