/**
 * @description: 双十一购物凑单（DP）
 * @author: michael ming
 * @date: 2019/7/17 0:29
 * @modified by: 
 */
#include <cstring>
#include <iostream>

const int limitMoney = 300;
const int MaxSumOfPrice = 3*limitMoney;//超过3倍就没有媷羊毛的必要了
void double11shopping(int *price, int n)
{
    bool (*states) [MaxSumOfPrice+1] = new bool [n][MaxSumOfPrice+1];
    memset(states,0,n*(MaxSumOfPrice+1)*sizeof(bool));
    states[0][0] = true;//第一个不买
    if(price[0] <= MaxSumOfPrice)
        states[0][price[0]] = true;//第一个买
    int i, j;
    for(i = 1; i < n; ++i)//动态规划
    {
        for(j = 0; j <= MaxSumOfPrice; ++j)//不买第i个商品
        {
            if(states[i-1][j] == true)
                states[i][j] = states[i-1][j];
        }
        for(j = 0; j <= MaxSumOfPrice-price[i]; ++j)//购买第i个商品
        {
            if(states[i-1][j] == true)
                states[i][j+price[i]] = true;
        }
    }

    for(j = limitMoney; j <= MaxSumOfPrice; ++j)
    {
        if(states[n-1][j] == true)
            break;//找到>=满减金额的最小值
    }
    if(j == MaxSumOfPrice+1)
        return;//超出满减金额很多，没必要选了，直接买吧

    for(i = n-1; i >= 1; --i)//打印该买的商品
    {
        if(j-price[i] >= 0 && states[i-1][j-price[i]] == true)
        {
            std::cout << "购买价格为：" << price[i] << " 的商品" << std::endl;
            j = j - price[i];
        }//else 没有购买这个商品，j不变
    }
    if(j != 0)//如果没有买第0个，到这里j == 0了，如果j不为0，说明买了第0个
        std::cout << "购买价格为：" << price[0] << " 的商品" << std::endl;
    delete [] states;
}
int main()
{
    const int n = 5;
    int price[n] = {100,98,105,104,99};
    double11shopping(price,n);
    return 0;
}