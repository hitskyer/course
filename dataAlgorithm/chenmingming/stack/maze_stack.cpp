//用栈解决走迷宫问题
// Created by mingm on 2019/3/29.
//
#include "stack.cpp"
#include <iostream>
#include <time.h>
#include <random>
using namespace std;


int mazepath()
{
    struct Move
    {
        int x_incr;
        int y_incr;
    };
    Move mvdir[4];  //定义四个移动方向
    mvdir[0].x_incr = 0;   mvdir[0].y_incr = 1;
    mvdir[0].x_incr = 1;   mvdir[0].y_incr = 0;
    mvdir[0].x_incr = 0;   mvdir[0].y_incr = -1;
    mvdir[0].x_incr = -1;   mvdir[0].y_incr = 0;

    struct Postion
    {
        int x;
        int y;
        int dir_opt;
    };

}
void make_maze_withWall(int **maze, int x, int y)   //生成带围墙的迷宫（围墙可以简化边界判断代码）
{
    srand((unsigned)time(NULL));
    for(int i = 1; i < x-1; ++i)    //随机填充内部迷宫
    {
        for(int j = 1; j < y-1; ++j)
        {
            *((int*)maze+i*y+j) = rand()%2;
        }
    }
    for(int i = 0; i < x; i += x-1)
    {
        for(int j = 0; j < y; ++j)
        {
            *((int*)maze+i*y+j) = 1;      //上下外围置1围墙障碍
        }
    }
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; j += y-1)
        {
            *((int*)maze+i*y+j) = 1;      //左右外围置1围墙障碍
        }
    }
}
void print_maze(int **maze, int x, int y)
{
    for(int i = 0; i < x; ++i)    //随机填充内部迷宫
    {
        int temp = 0;
        for(int j = 0; j < y; ++j)
        {
            cout << *((int*)maze+i*y+j) << " ";
            temp++;
        }
        if(temp == y)
            cout << endl;
    }
}
int main()
{
    cout << "请输入矩形迷宫的长宽："  << endl;
    int m, n, x0 = 0, y0 = 0;
    cin >> m >> n;
    int **maze = new int* [n+2]; //定义地图矩阵
    make_maze_withWall(maze,m+2,n+2);
    print_maze(maze,m+2,n+2);
    return 0;
}
