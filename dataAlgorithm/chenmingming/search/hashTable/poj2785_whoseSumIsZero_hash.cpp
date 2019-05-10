/**
 * @description: 4个数和为0的方案数，哈希法
 * @author: michael ming
 * @date: 2019/5/9 22:30
 * @modified by: 
 */
#include <iostream>
#include <memory.h>
using namespace std;
int a[4001], b[4001], c[4001], d[4001];
int ab[4000*4000+1], cd[4000*4000+1];   //存储a+b，c+d
int *hasht = new int[16000057];
int offset = 1000000000;
int hashfunc(int &value)
{
    int mod = 16000057;
    return (value%mod + value/mod)%mod;
}
int main()
{
    int line, k=0, value;
    cin >> line;
    memset(hasht, 0, sizeof(hasht));
    for(int i = 0; i < line; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 0; i < line; ++i)
    {
        for(int j = 0; j < line; ++j)
        {
            ab[k] = a[i]+b[j];
            value = ab[k]+offset;
            hasht[hashfunc(value)]++;
            cd[k++] = -(c[i]+d[j]);
        }
    }
    int result = 0;
    for(int i = 0; i < k; ++i)
    {
        value = cd[i]+offset;
        if(hasht[hashfunc(value)])
            result += hasht[hashfunc(value)];
    }
    cout << result << endl;
    delete [] hasht;
    return 0;
}