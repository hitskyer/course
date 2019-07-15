/**
 * @description: 
 * @author: michael ming
 * @date: 2019/7/15 22:00
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 9   //背包承载极限
const int N = 5;    //背包个数
using namespace std;
bool states[MaxWeight+1];//全局参数自动初始化，默认是false
int fill_dp(int *bag, int N)
{
    states[0] = true;//第1个背包不放
    if(bag[0] <= MaxWeight)
        states[bag[0]] = true;//第1个背包放
    for(int i = 1; i < N; ++i)//动态规划状态转移
    {
        for(int j = MaxWeight-bag[i]; j >= 0; --j)//把第i个物品放入背包
        {
            if(states[j] == true)
                states[j+bag[i]] = true;
        }
    }
    for(int i = MaxWeight; i >= 0; --i)//输出结果
    {
        if(states[i] == true)
            return i;//最大重量
    }
    return 0;
}
int main()
{
    int bag[N] = {2,2,4,6,3};
    cout << "最大可装进背包的重量是：" << fill_dp(bag,N);
    return 0;
}