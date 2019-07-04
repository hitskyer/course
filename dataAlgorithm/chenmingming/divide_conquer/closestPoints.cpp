/**
 * @description: 2维平面寻找距离最近的点对（分治）
 * @author: michael ming
 * @date: 2019/7/4 23:16
 * @modified by: 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
#define LEFT_BOUND 0.0
#define RIGHT_BOUND 100.0
#define LOWER_BOUND 0.0
#define UPPER_BOUND 100.0   //随机点的范围
using namespace std;
class Point
{
public:
    int id;
    double x, y;
    Point(int index, double x0, double y0):id(index),x(x0),y(y0){}
};
typedef vector<Point> PointVec;
bool compx(const Point &a, const Point &b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
PointVec points_vec;
bool compy(const int &a, const int &b)
{
    return points_vec[a].y < points_vec[b].y;
}
class ClosestPoint
{
    PointVec points_vec;
    int numOfPoint;
public:
    ClosestPoint()
    {
        double x, y;
        cout << "请输入测试点个数，将随机生成散点：";
        cin >> numOfPoint;
        for(int i = 0; i < numOfPoint; ++i)
        {
            x = LEFT_BOUND + (double)rand()/RAND_MAX *(RIGHT_BOUND-LEFT_BOUND);
            y = LOWER_BOUND + (double)rand()/RAND_MAX *(UPPER_BOUND-LOWER_BOUND);
            cout << i+1 << " (" << x << "," << y << ")" << endl;
            points_vec.emplace_back(i+1,x,y);//生成点的动态数组
        }
    }



    double dist(const Point &a, const Point &b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);//返回两点之间的距离
    }
    void bfCalDist()
    {
        size_t num = points_vec.size();
        if(num <= 1)
        {
            cout << "输入个数<=1 !!!" << endl;
            return;
        }
        int i, j, s, t;
        double distance = RAND_MAX, d;
        for(i = 0; i < num; ++i)
            for(j = i+1; j < num; ++j)
            {
                d = dist(points_vec[i], points_vec[j]);
                if(d < distance)
                {
                    distance = d;
                    s = points_vec[i].id;
                    t = points_vec[j].id;
                }
            }
        cout << "点" << s << "到点" << t << "的距离最小：" << distance << endl;
        cout << "---------------------------------" << endl;
    }
    double calcDist(size_t left, size_t right, size_t &s, size_t &t)
    {
        if(left == right)//一个点
            return RAND_MAX;
        if(left+1 == right)//两个点，直接计算距离
        {
            s = points_vec[left].id;
            t = points_vec[right].id;
            return dist(points_vec[left],points_vec[right]);
        }
        sort(points_vec.begin()+left,points_vec.begin()+right+1,compx);
        size_t mid = (left+right)/2;
        double mid_x = points_vec[mid].x;
        double distance = RAND_MAX, d;
        distance = min(distance,calcDist(left,mid,s,t));
        distance = min(distance,calcDist(mid+1,right,s,t));
        size_t ID[right-left+1], i, j, k = 0;
        for(i = left; i <= right; ++i)
        {
            if(fabs(points_vec[i].x-mid_x) <= distance)
                ID[k++] = i;
        }
        sort(ID,ID+k,compy);
        for(i = 0; i < k; ++i)
        {
            for(j = i+1; j < k && points_vec[ID[j]].y-points_vec[ID[i]].y < distance; ++j)
            {
                d = dist(points_vec[ID[i]],points_vec[ID[j]]);
                if(d < distance)
                {
                    distance = d;
                    s = points_vec[ID[i]].id;
                    t = points_vec[ID[j]].id;
                }
            }
        }
        return distance;
    }
    void closestDist()
    {
        size_t num = points_vec.size();
        if(num <= 1)
        {
            cout << "输入个数<=1 !!!" << endl;
            return;
        }
        size_t s, t; s = t = 0;//记录起终点
        double d = calcDist(0,num-1,s,t);
        cout << "点" << s << "到点" << t << "的距离最小：" << d << endl;
    }

};
int main()
{
    ClosestPoint cp;
    srand(unsigned(time(0)));
    clock_t start, end;
    cout << "方法1，暴力求解：" << endl;
    start = clock();
    cp.bfCalDist();
    end = clock();
    cout << "耗时：" << (double)(end - start) << "ms." << endl;
    cout << "方法2，分治求解：" << endl;
    start = clock();
    cp.closestDist();
    end = clock();
    cout << "耗时：" << (double)(end - start) << "ms." << endl;
    return 0;
}