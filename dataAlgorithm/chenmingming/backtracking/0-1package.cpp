/**
 * @description: 0-1背包--回溯应用
 * @author: michael ming
 * @date: 2019/7/9 1:13
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 51   //背包承载极限
using namespace std;
void fill(int i, int curWeight, int *bag, int N, int &maxweightinbag)
{
    if(curWeight == MaxWeight || i == N)//
    {
        if(curWeight > maxweightinbag)
            maxweightinbag = curWeight;//记录历史最大装载量
        return;
    }
    fill(i+1,curWeight,bag,N,maxweightinbag);
    if(curWeight+bag[i] <= MaxWeight)
    {
        fill(i+1,curWeight+bag[i],bag,N,maxweightinbag);
    }
}
int main()
{
    const int N = 10;
    int bag[N] = {15,40,6,11,4,7,9,13,45,10};
    int maxweightinbag = 0;
    fill(0,0,bag,N,maxweightinbag);
    cout << "最大可装进背包的重量是：" << maxweightinbag;
    return 0;
}