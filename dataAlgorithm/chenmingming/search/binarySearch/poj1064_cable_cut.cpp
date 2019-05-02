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
//        cin >> len[i];
        scanf("%lf", &len[i]);
//        len[i] += 1E-15;
//        maxlen = maxlen > len[i] ? maxlen : len[i];
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
//    mid = double(floor(mid*100))/100.0;
//    cout << fixed << setprecision(2) << mid << endl;
    printf("%.2lf\n", floor(mid*100)/100);
    return 0;
}