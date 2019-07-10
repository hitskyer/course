/**
 * @description: 0-1背包--回溯应用
 * @author: michael ming
 * @date: 2019/7/9 1:13
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 76   //背包承载极限
using namespace std;
void fill(int i, int curWeight, int *bag, int N, int &maxweightinbag)
{
    if(curWeight == MaxWeight || i == N)//到达极限了，或者考察完所有物品了
    {
        if(curWeight > maxweightinbag)
            maxweightinbag = curWeight;//记录历史最大装载量
        return;
    }
    fill(i+1,curWeight,bag,N,maxweightinbag);
    if(curWeight+bag[i] <= MaxWeight)
    {//没有达到极限，继续装
        fill(i+1,curWeight+bag[i],bag,N,maxweightinbag);
    }
}
int main()
{
    const int N = 4;
    int bag[N] = {15,6,40,21};
//    int bag[N] = {1,2,3,4};
    int maxweightinbag = 0;
    fill(0,0,bag,N,maxweightinbag);
    cout << "最大可装进背包的重量是：" << maxweightinbag;
    return 0;
}