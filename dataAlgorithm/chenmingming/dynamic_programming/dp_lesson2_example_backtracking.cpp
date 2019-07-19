/**
 * @description: dp课第二节，案例回溯法求解
 * @author: michael ming
 * @date: 2019/7/19 12:55
 * @modified by: 
 */
#include <iostream>
#define N 4//地图大小
#define k (2*N-1)//需要走的步数
using namespace std;
int selectWay[k], shortestWay[k];
void step(int (*map)[N], int s, int &mins, int r, int c, int idx)
{
    selectWay[idx++] = map[r][c];//记录选择的路
    if(r == N-1 && c == N-1)
    {
        if(s < mins)
        {
            mins = s;//更新最小的总路程
            for(int i = 0; i < k; ++i)//把最终的路线记录下来
                shortestWay[i] = selectWay[i];
        }
        return;
    }
    if(r == N || c == N)
        return;//走出地图了
    step(map,s+map[r+1][c],mins,r+1,c,idx);//往下走
    step(map,s+map[r][c+1],mins,r,c+1,idx);//往右走
}
int main()
{
    int s = 0, mins = 65535;
    int map[N][N] = {0,3,5,9,2,1,3,4,5,2,6,7,6,8,4,3};
    step(map,s+map[0][0],mins,0,0,0);
    cout << "最短路径是：" << mins << endl;
    cout << "走过的点的距离分别是：" << endl;
    for(int i = 0; i < k; ++i)
        cout << shortestWay[i] << " ";
    return 0;
}