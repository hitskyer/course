/**
 * @description: 贪心算法--区间覆盖应用
 * (给定每个人可以在一个房间内活动的时间，要求让最多的人在这个房间活动，打印出这些人)
 * @author: michael ming
 * @date: 2019/6/29 23:34
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
using namespace std;
struct Interval
{
    int left, right;
    bool operator<(const Interval &sel_idx) const
    {
        if(left == sel_idx.left)
            return right < sel_idx.right;//左端点相等，取右端小的
        else
            return left < sel_idx.left;//左端不等，取左端小的
    }
    bool belongto(int l, int r)//区间属于[l,r]的子集
    {
        return left >= l && right <= r;
    }
    bool absnotbelong(int l, int r)//两个区间完全无重叠
    {
        return left >= r || right <= l;
    }
};
int main()
{
    const int N = 10;//区间数量
    int left = 1, right = 10;//大区间左右端点（房间开放时间）
    int select[N];//存储选出来的区间（人）id
    int i, j, k, sel_idx = 0;
    for(i = 0; i < N; ++i)
    {
        select[i] = -1;
    }
    Interval qujian[N] = {{1,5},{2,4},{3,5},{5,9},{6,8},{8,10},{2,3},{-1,4},{5,12},{4,5}};//所有人的占用时间段
    sort(qujian,qujian+N);//对区间进行排序（先按开始时间早排序，一样早，按占用时间少排前面）
    for(i = 0; i < N; ++i)
    {
        if(qujian[i].left >= left && qujian[i].right <= right)//占用时间在开放时间内
        {
            while(sel_idx != 0 && !qujian[i].absnotbelong(qujian[select[sel_idx-1]].left,qujian[select[sel_idx-1]].right))
            {//如果有人占用了房间，一直找到第一个跟他时间不冲突的人
                ++i;
            }
            for(k = i, j = k+1; j < N; ++j)
            {//找到时间是不冲突那个人的最小子集的人
                if(qujian[j].belongto(qujian[k].left,qujian[k].right))
                {
                    k = j;
                }
            }
            select[sel_idx++] = k;//占用最短的那个人选出来
            i = k;//从这个人开始再往后找
        }
    }
    cout << "total selected " << sel_idx << " people, their time as following:" << endl;
    for(i = 0; i < N && select[i] != -1; ++i)
    {//打印被选出来的人的时间信息
        cout << i << ": [" << qujian[select[i]].left << ","
                << qujian[select[i]].right << "]" << endl;
    }
    return 0;
}