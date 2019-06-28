/**
 * @description: 贪心应用--找零钱
 * @author: michael ming
 * @date: 2019/6/28 22:02
 * @modified by: 
 */
#include <iostream>
#include <memory.h>
#include <math.h>
#define N 10
using namespace std;
bool exchange(float money, float *rmb, int i0, int *amount)
{
    if(money < 0.1)
        return true;
    int i = i0, k = 0;
    money = round(money*10)/10.0;//四舍五入掉分
    for(;k == 0 && i < N; ++i)
    {
        k = money/rmb[i];
        amount[i] = k;
    }
    if(k == 0)
        return false;
    else
        return exchange(money-k*rmb[i-1],rmb,i,amount);
}
int main()
{
    float rmb[N] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1};
    int amount[N];
    memset(amount,0,N*sizeof(int));
    float money;
    cout << "请输入要找的钱的金额：";
    cin >> money;
    money = round(money*10)/10.0;//四舍五入掉分
    cout << "找零结果如下(分位四舍五入)：" << endl;
    if(exchange(money,rmb,0,amount))
    {
        int i = 0;
        while(i < N)
        {
            if(amount[i] != 0)
                cout << amount[i] << "个" << rmb[i] << " ";
            i++;
        }
    }
    else
        cout << "不能凑出该金额！" << endl;
}