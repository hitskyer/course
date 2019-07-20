/**
 * @description: 找零钱，需要张数最少
 * @author: michael ming
 * @date: 2019/7/20 18:35
 * @modified by: 
 */
#include <iostream>
#define N 3
int rmb[N] = {1,9,10};//钞票面额
int amount[N];
int minAmount[N];
using namespace std;
void exchange(const int &targetMoney, int curMoney, int &minPiece, int piece)
{
    if(curMoney > targetMoney)//超过目标，返回
        return;
    if(curMoney == targetMoney)//达到目标金额
    {
        if(piece < minPiece)
        {
            minPiece = piece;//更新最小张数
            for(int i = 0; i < N; ++i)
                minAmount[i] = amount[i];//获取每张钞票的张数
        }
        return;
    }
    for(int i = 0; i < N; ++i)
    {//递归调用,拿取每张面额的钞票
        amount[i]++;
        exchange(targetMoney,curMoney+rmb[i],minPiece,piece+1);
        amount[i]--;//恢复上次的状态
    }
}
int main()
{
    int minPiece = 65535, piece = 0,targetMoney = 18, curMoney = 0;
    exchange(targetMoney,curMoney,minPiece,piece);
    cout << "凑成" << targetMoney << "元，最少需要：" << minPiece << "张(枚)。" << endl;
    int i = 0;
    while(i < N)
    {
        if(minAmount[i] != 0)
            cout << minAmount[i] << "个" << rmb[i] << " ";
        i++;
    }
    cout << endl;
    cout << "----------------------" << endl;
}