/**
 * @description: 0-1背包--dp应用
 * @author: michael ming
 * @date: 2019/7/9 1:13
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 9   //背包承载极限
const int N = 5;    //背包个数
using namespace std;
bool states[N][MaxWeight+1];//全局参数自动初始化，默认是false
int fill(int i, int curWeight, int *bag, int N, int &maxweightinbag)
{
    states[0][0] = true;
    if(bag[0] <= MaxWeight)
        states[0][bag[0]] = true;
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j <= MaxWeight; ++j)
        {
            if(states[i-1][j] == true)
                states[i][j] = states[i-1][j];
        }
        for(int j = 0; j <= MaxWeight-bag[i]; ++j)
            if(states[i-1][j] == true)
                states[i][j+bag[i]] = true;
    }
    for(int i = MaxWeight; i >= 0; --i)
    {
        if(states[N-1][i] == true)
            return i;
    }
    return 0;
}
int main()
{
    int bag[N] = {2,2,4,6,3};
    int maxweightinbag = 0;
    fill(0,0,bag,N,maxweightinbag);
    cout << "最大可装进背包的重量是：" << maxweightinbag;
    return 0;
}