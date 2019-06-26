/**
 * @description: poj1064，多根电缆切成指定段数（相同长度），求每段最大长度
 * @author: michael ming
 * @date: 2019/5/2 15:14
 * @modified by: 
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    int cables, target, cable_we_get;
    cin >> cables >> target;
    double minlen = 0.0, maxlen = 100000, mid, len[10001];
    for(int i = 0; i < cables; ++i)
    {
        cin >> len[i];
//        scanf("%lf", &len[i]);
    }
    while(maxlen - minlen > 1E-3)
    {
        cable_we_get = 0;
        mid = minlen + (maxlen - minlen)/2;
        for(int i = 0; i < cables; ++i)
        {
            cable_we_get += (int)(len[i]/mid);
        }
        if(cable_we_get >= target)
            minlen = mid;
        else
            maxlen = mid;
    }
    cout << fixed << setprecision(2) << floor(maxlen*100)/100.0 << endl;
//    printf("%.2lf\n", floor(maxlen*100)/100);
//  以上两种写法都可以AC，但是注意表达式内不要写mid，要写maxlen
//  最后如果是mid=1.999，保留两位，直接是1.99
//  maxlen是2.001,直接保留2.00
    return 0;
}