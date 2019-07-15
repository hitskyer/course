/**
 * @description: 0-1背包带价值，dp解法
 * @author: michael ming
 * @date: 2019/7/16 0:07
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 9   //背包承载极限
const int N = 5;    //背包个数
using namespace std;
int fill_value_dp(int* weight, int* value, int N)
{
    int (*states) [MaxWeight+1]  = new int [N][MaxWeight+1];
    for (int i = 0; i < N; ++i) // 初始化 states
    {
        for (int j = 0; j < MaxWeight+1; ++j)
            states[i][j] = -1;
    }
    states[0][0] = 0;//第一个不放，价值0存入states
    if (weight[0] <= MaxWeight)
    {
        states[0][weight[0]] = value[0];//第一个放入背包
    }
    for (int i = 1; i < N; ++i) // 动态规划，状态转移
    {
        for (int j = 0; j <= MaxWeight; ++j)
        { // 不选择第 i 个物品
            if (states[i-1][j] >= 0)
                states[i][j] = states[i-1][j];//直接复制上一层的状态
        }
        for (int j = 0; j+weight[i] <= MaxWeight; ++j)
        { // 选择第 i 个物品
            if (states[i-1][j] >= 0)
            {
                int v = states[i-1][j] + value[i];
                if (v > states[i][j+weight[i]])
                {//只存价值最大的
                    states[i][j+weight[i]] = v;
                }
            }
        }
    }
    // 找出最大值
    int maxvalue = -1;// 最大价值放到 maxvalue 中
    for (int j = 0; j <= MaxWeight; ++j)
    {
        if (states[N-1][j] > maxvalue)
            maxvalue = states[N-1][j];
    }
    return maxvalue;
}
int main()
{
    int weight[5] = {2,2,4,6,3};  // 物品的重量
    int value[5] = {3,4,8,9,6}; // 物品的价值
    cout << "最大可装进背包的价值是：" << fill_value_dp(weight,value,N);
    return 0;
}