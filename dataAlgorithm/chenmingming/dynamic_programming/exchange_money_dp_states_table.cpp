/**
 * @description: 找零钱，需要张数最少,dp状态表法
 * @author: michael ming
 * @date: 2019/7/21 20:01
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
#include <memory.h>

#define N 3
const int targetMoney = 18;//目标金额
int rmb[N] = {1,9,10};//钞票面额,从小到大
using namespace std;
int exchange(int Money)
{
    int maxPiece = targetMoney/rmb[0];//最大张数
    int i, j, k;
    int (*states)[targetMoney+1] = new int [maxPiece][targetMoney+1];
    //memset(states,65535,maxPiece*(targetMoney+1)*sizeof(int));
    //上面错误！！！memset一般只付0或极大值
    for(i = 0; i < maxPiece; ++i)
        for(j = 0; j <= targetMoney; ++j)
            states[i][j] = 65535;
    for(i = 0, j = 0; j <= targetMoney; ++j)
    {
        if(i < N && j == rmb[i])
        {//初始化第一行数据
            states[0][j] = 1;//一张rmb
            i++;
        }
    }
    for(i = 1; i < maxPiece; ++i)
    {
        for(j = 0; j <= targetMoney; ++j)//上面一行的数据考下来
            states[i][j] = states[i-1][j];
        for(j = 0; j <= targetMoney; ++j)
        {
            if(states[i-1][j] != 65535)
            {
                for(k = 0; k < N; ++k)
                {
                    if(j+rmb[k] <= targetMoney
                        && states[i-1][j+rmb[k]] > states[i-1][j]+1)
                        states[i][j+rmb[k]] = states[i-1][j]+1;

                }
            }
        }
    }
    cout << "凑成" << targetMoney << "元，最少需要："
         << states[maxPiece-1][targetMoney] << "张(枚)。" << endl;
    //------------打印选择的信息---------------------------
    
    return 0;
}
int main()
{
    exchange(targetMoney);
}