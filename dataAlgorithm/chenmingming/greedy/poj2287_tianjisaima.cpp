/**
 * @description: poj2287田忌赛马（贪心）
 * @author: michael ming
 * @date: 2019/7/2 23:55
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int i, j, iend, jend, n, money;
    int tianji[1001], king[1001];
    while(cin >> n && n != 0)
    {
        for(i = 0; i < n; ++i)
            cin >> tianji[i];
        for(j = 0; j < n; ++j)
            cin >> king[j];
        sort(tianji, tianji+n, comp);//从大到小排序
        sort(king, king+n, comp);//从大到小排序
        i = j = 0;
        iend = jend = n-1;
        money = 0;
        while(i <= iend)
        {
            if(tianji[i] > king[j])//我方能打赢所有的，那么我就打掉一个最厉害的
            {
                money += 200;
                i++,j++;
            }
            else if(tianji[i] < king[j])//我方最大的都比别人小，让最弱的出战
            {
                money -= 200;
                iend--,j++;
            }
            else//两边最厉害的一样
            {
                if(tianji[iend] > king[jend])//最弱的马都能打败你的最弱马，那就用最小实力的
                {
                    money += 200;
                    iend--,jend--;
                }
                else if(tianji[iend] < king[jend])//我最弱的马没有胜算，让给你最强的马吃掉
                {
                    money -= 200;
                    iend--,j++;
                }
                else//两边最厉害的，和最弱的都一样，
                {
                    if(tianji[iend] < king[j])
                        money -= 200;//我最弱的给你最强的吃掉
                    iend--,j++;
                    //如果tianji[iend] == king[j]，说明剩余的全部相等，打平，金钱不变
                }
            }
        }
        cout << money << endl;
    }
    return 0;
}