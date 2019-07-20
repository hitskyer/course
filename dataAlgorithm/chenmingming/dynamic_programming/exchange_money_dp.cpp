/**
 * @description: 找零钱，需要张数最少
 * @author: michael ming
 * @date: 2019/7/20 18:35
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
#include <memory.h>

#define N 3
const int targetMoney = 18;//目标金额
int rmb[N] = {1,9,10};//钞票面额
int mem[targetMoney+1];//备忘录，存放最小张数
using namespace std;
int minP(int Money)
{
    if(Money < 0)//超过目标，返回很大的张数，表示不可能凑成
        return 65535;
    if(Money == 0)//达到目标金额
        return 0;
    if(mem[Money] > 0)//计算过了，直接读取备忘录
        return mem[Money];
    int minAmount[N];
    memset(minAmount,65535,N*sizeof(int));
    for(int i = 0; i < N; ++i)
    {//递归调用,拿取每张面额的钞票
        minAmount[i] = minP(Money-rmb[i]);
    }
    sort(minAmount,minAmount+N);
    mem[Money] = minAmount[0]+1;//记录最小的张数
    return mem[Money];
}
int main()
{
    cout << "凑成" << targetMoney << "元，最少需要："
        << minP(targetMoney) << "张(枚)。" << endl;
    //如何打印出选取钞票的面额和张数？？？
}