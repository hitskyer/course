/**
 * @description: 求四个数相加等于0的组合种数
 * @author: michael ming
 * @date: 2019/5/8 22:18
 * @modified by:
 */
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
int a[4001], b[4001], c[4001], d[4001];
int ab[4000*4000+1], cd[4000*4000+1];   //存储a+b，c+d
int findSameValue(int value, int maxindex)//二分查找
{
    int low = 0, high = maxindex, mid, index, count=0;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(value == cd[mid])    //查找前后满足要求的个数
        {
            index = mid - 1;
            while(index >= 0 && value == cd[index--])
                count++;
            index = mid + 1;
            while(index <= high && value == cd[index++])
                count++;
            return count + 1;
        }
        else if(value < cd[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int main()
{
    int line, k=0;
    cin >> line;
    memset(ab, 0, sizeof(ab));
    memset(cd, 0, sizeof(cd));
    for(int i = 0; i < line; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 0; i < line; ++i)
    {
        for(int j = 0; j < line; ++j)
        {
            ab[k] = a[i]+b[j];
            cd[k++] = -(c[i]+d[j]);
        }
    }
    sort(cd,cd+k);  //二分查找的必要条件，有序
    int result = 0;
    for(int i = 0; i <= k-1; ++i)
        result += findSameValue(ab[i], k-1);
    cout << result << endl;
    return 0;
}