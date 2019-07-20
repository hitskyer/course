/**
 * @description: 找零钱，需要张数最少
 * @author: michael ming
 * @date: 2019/7/20 18:35
 * @modified by: 
 */
#include <iostream>
#include <memory.h>
#include <math.h>
#define N 10
using namespace std;
void exchange(float money, float *rmb, int *amount)
{
    if(money < 0.1)
        return;
    int i, k = 0;
    for(i = 0; i < N; ++i)
    {
        money = round(money*10)/10.0;//四舍五入掉分
        k = money/rmb[i];
        amount[i] = k;
        money = money-k*rmb[i];
    }
}
int main()
{
    float rmb[N] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1};
    int amount[N];
    while(1)
    {
        memset(amount,0,N*sizeof(int));
        float money;
        cout << "请输入要找的钱的金额：";
        cin >> money;
        money = round(money*10)/10.0;//四舍五入掉分
        cout << "找零结果如下(分位四舍五入)：" << endl;
        exchange(money,rmb,amount);
        int i = 0;
        while(i < N)
        {
            if(amount[i] != 0)
                cout << amount[i] << "个" << rmb[i] << " ";
            i++;
        }
        cout << endl;
        cout << "----------------------" << endl;
    }
}