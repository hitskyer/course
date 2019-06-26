/**
 * @description: poj1064 数字放大100倍做法,输入浮点数分成整数部分和小数部分，避免1.50输入后变成1.4999999
 * @author: michael ming
 * @date: 2019/5/2 20:00
 * @modified by: 
 */
#include <iostream>
using namespace std;
int main()
{
    int cables, target, cable_we_get;
    cin >> cables >> target;
    int minlen = 1, maxlen = 10000000, mid, len[10001], ans;
    int int_part, float_part;
    char ch;
    for(int i = 0; i < cables; ++i)
    {
        cin >> int_part >> ch >> float_part;
        len[i] = int_part * 100 + float_part;
    }
    while(maxlen - minlen >= 0)
    {
        cable_we_get = 0;
        mid = minlen + (maxlen - minlen)/2;
        for(int i = 0; i < cables; ++i)
        {
            cable_we_get += len[i]/mid;
        }
        if(cable_we_get >= target)
            minlen = mid+1;
        else
            maxlen = mid-1;
    }
    cout << maxlen/100 << "." << (maxlen/10)%10 << maxlen%10 << endl;
    return 0;
}