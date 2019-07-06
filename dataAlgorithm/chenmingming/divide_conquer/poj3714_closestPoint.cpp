/**
 * @description: poj3714求解最近的核电站距离
 * @author: michael ming
 * @date: 2019/7/6 0:09
 * @modified by: 
 */
#include<iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define DBL_MAX 1.7976931348623158e+308
using namespace std;
class Point//点
{
public:
    int id;
    int x, y;
    Point(int index, int x0, int y0):id(index),x(x0),y(y0){}
};
typedef vector<Point> PointVec;
bool compx(const Point &a, const Point &b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
bool compy(const Point &a, const Point &b)
{
    return a.y < b.y;
}

class ClosestPoint
{
    PointVec points_vec;
    int numOfPoint;
public:
    ClosestPoint()
    {
        int x, y;
        cin >> numOfPoint;
        for(int i = 0; i < numOfPoint; ++i)
        {
            cin >> x >> y;
            points_vec.push_back(Point(0,x,y));//生成站点的动态数组（0表示站）
        }
        for(int i = 0; i < numOfPoint; ++i)
        {
            cin >> x >> y;
            points_vec.push_back(Point(1,x,y));//加入人的位置（1表示人）
        }
    }

    double dist(const Point &a, const Point &b)
    {
        if(a.id == b.id)
            return DBL_MAX;
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return sqrt(double(dx*dx + dy*dy));//返回两点之间的距离
    }

    double calcDist(size_t left, size_t right)
    {
        if(left == right)//一个点,返回无穷大
            return DBL_MAX;
        if(left+1 == right)//两个点，直接计算距离
        {
            return dist(points_vec[left],points_vec[right]);
        }
        sort(points_vec.begin()+left,points_vec.begin()+right+1,compx);
        //把点群按照x排序
        size_t mid = (left+right)/2;
        double mid_x = points_vec[mid].x;
        double distance = DBL_MAX, d;
        distance = min(distance,calcDist(left,mid));//递归划分左边
        distance = min(distance,calcDist(mid+1,right));//递归划分右边
        size_t i, j, k = 0;
        PointVec temp;//存储临时点（在mid_x左右d范围内的）
        for(i = left; i <= right; ++i)
        {
            if(fabs(points_vec[i].x-mid_x) <= distance)
            {
                temp.push_back(Point(points_vec[i].id,points_vec[i].x,points_vec[i].y));
                k++;
            }
        }
        sort(temp.begin(),temp.end(),compy);//再把范围内的点，按y排序
        for(i = 0; i < k; ++i)
        {
            for(j = i+1; j < k && temp[j].y-temp[i].y <= distance; ++j)
            {//在临时点里寻找距离更小的，内层循环最多执行不超过4次就会退出
                d = dist(temp[i],temp[j]);
                if(d < distance)
                {
                    distance = d;
                }
            }
        }
        return distance;
    }
    double closestDist()//调用分治求解
    {
        size_t num = points_vec.size();
        return calcDist(0,num-1);
    }

};
int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        ClosestPoint cp;
        cout << fixed << setprecision(3) << cp.closestDist() << endl;
    }
    return 0;
}