/**
 * @description: 双十一购物凑单（DP）
 * @author: michael ming
 * @date: 2019/7/17 0:29
 * @modified by: 
 */
#include <cstring>
const int limitMoney = 300;
const int MaxSumOfPrice = 3*limitMoney;//超过3倍就没有媷羊毛的必要了
void double11shopping(int *price, int n)
{
    bool (*states) [MaxSumOfPrice+1] = new bool [n][MaxSumOfPrice+1];
    memset(states,0,(MaxSumOfPrice+1)* sizeof(bool));
    states[0][0] = true;//第一个不买
    if(price[0] <= MaxSumOfPrice)
        states[0][price[0]] = true;//第一个买
    for(int i = 1; i < n; ++i)//动态规划
    {
        for(int j = 0; j <= MaxSumOfPrice; ++j)//不买第i个商品
    }
}
int main()
{
    const int n = 5;
    int price[n] = {100,98,105,110,99};
    double11shopping(price,n);
    return 0;
}