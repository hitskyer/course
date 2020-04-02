/**
 * @Description: 树状数组
 * @Author: michael ming
 * @Date: 2020/4/1 23:38
 * @Modified by: 
 * @Website: https://michael.blog.csdn.net/
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int a[N+1]={0,1,2,3,4,5,6,7,8}, c[N+1] = {0}; //对应原数组和树状数组
int sum1[N+1] = {0}, sum2[N+1] = {0}; //对应D[i] , D[i]*(i-1)
int lowbit(int x){
    return x&(-x);
}
//-------单点修改----------
void update(int i, int delta){    //在i位置加上delta（单点）
    while(i <= N){
        c[i] += delta;
        i += lowbit(i);
    }
}

int query(int i){    //求A[1],A[2],...A[i]的和
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

//------区间修改-------
void update1(int i, int delta){    //在i位置加上delta
    int x = i;//系数不能变，先存起来
    while(i <= N){
        sum1[i] += delta;
        sum2[i] += delta*(x-1);
        i += lowbit(i);
    }
}
void update_range(int l, int r, int delta)    //给区间加上delta
{
    update1(l, delta);//只需修改L，R+1，左+，右-
    update1(r+1, -delta);
}

int query_p(int i){
    int res = 0, x = i;//系数不能变，先存起来
    while(i > 0){
        res += x*sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}
int query_range(int l, int r)//区间[l,r]的和
{
    return query_p(r)-query_p(l-1);
}
int main(){
    //单点修改
    cout << "单点修改，单点查询" << endl;
    for(int i = 1; i <= N; ++i)
        update(i,a[i]);//读取原数据，插入树状数组
    cout << query(3) << endl;//获取前3个数的和
    cout << query(8) << endl;
    update(3,2);
    cout << query(3) << endl;
    cout << query(8) << endl;
    cout << query(4)-query(2) << endl;//获取A[3],A[4]的区间和
    cout << "区间修改，单点查询" << endl;
    for(int i = 1; i <= N; ++i)
        update1(i,a[i]-a[i-1]);//读取原数据差值，插入树状数组
    cout << query_p(3) << endl;//获取前3个数的和
    cout << query_p(8) << endl;
    update_range(3,3,2);//修改区间【3，3】，都加上2
    cout << query_p(3) << endl;
    cout << query_p(8) << endl;
    cout << query_range(3,4) << endl;//获取A[3],A[4]的区间和
    return 0;
}