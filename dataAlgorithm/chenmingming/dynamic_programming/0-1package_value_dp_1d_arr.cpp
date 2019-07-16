/**
 * @description: 0-1背包带价值，dp解法(状态存储用一维数组)
 * @author: michael ming
 * @date: 2019/7/16 22:17
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 9   //背包承载极限
const int N = 5;    //背包个数
using namespace std;
int fill_value_dp(int* weight, int* value, int N)
{
    int *states  = new int [MaxWeight+1];
    for (int i = 0; i < MaxWeight+1; ++i) // 初始化 states
    {
        states[i] = -1;
    }
    states[0] = 0;//第一个不放，价值0存入states
    if (weight[0] <= MaxWeight)
    {
        states[weight[0]] = value[0];//第一个放入背包
    }
    for (int i = 1; i < N; ++i) // 动态规划，状态转移
    {
        for (int j = MaxWeight-weight[i]; j >= 0; --j)
//        for (int j = 0; j <= MaxWeight-weight[i]; ++j)
        { // 选择第 i 个物品
            if (states[j] >= 0)
            {
                int v = states[j] + value[i];
                if (v > states[j+weight[i]])
                {//只存价值最大的
                    states[j+weight[i]] = v;
                }
            }
        }
    }
    // 找出最大值
    int maxvalue = -1;// 最大价值放到 maxvalue 中
    for (int i = 0; i <= MaxWeight; ++i)
    {
        if (states[i] > maxvalue)
            maxvalue = states[i];
    }
    delete [] states;
    return maxvalue;
}
int main()
{
    int weight[N] = {2,2,4,6,3};  // 物品的重量
    int value[N] = {3,4,8,9,6}; // 物品的价值
    cout << "最大可装进背包的价值是：" << fill_value_dp(weight,value,N);
    return 0;
}