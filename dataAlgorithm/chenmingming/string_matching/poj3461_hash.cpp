/**
 * @description: poj 3461 字符串匹配，哈希法
 * @author: michael ming
 * @date: 2019/6/26 21:59
 * @modified by: 
 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
#define K 25    //K大于等于字符集数 k>=25
typedef unsigned long long ull;
char a[1000001], b[10001];
ull ha[1000001];
ull powk[1000001];//存储K的幂值
using namespace std;
void fillpowk(int n)
{
    powk[0] = 1;
    for(int i = 1; i < n; ++i)
        powk[i] = powk[i-1]*K;
}
ull hashf(int m, char *str)
{
    ull value = 0;
    for(int i = 0; i < m; ++i)
        value = value * K + str[i];
    return value;
}
int str_RK(char *a, int n, char *b, int m)//a是主串，b是模式串
{
    fillpowk(n);
    int i, times = 0;
    ull hash_val, value = 0;
    value = hashf(m,b); //计算模式串的hash值value
    ha[0] = ull(a[0]);
    for(i = 1; i < n; ++i)
        ha[i] = ha[i-1] * K + a[i];
    for(i = 0; i < n-m+1; ++i)//最多n-m+1次比较
    {
        if(i == 0)
            hash_val = hashf(m,a);
        else
            hash_val = ha[i+m-1] - ha[i-1]*powk[m];
        if(hash_val == value)
        {//如果子串哈希值等于模式串的，匹配成功（无冲突）
            times++;
        }
    }
    return times;
}
int main()
{
    int count;
    std::cin >> count;
    while(count--)
    {
        scanf("%s",&b);
        scanf("%s",&a);
        printf("%d\n",str_RK(&a[0], strlen(a), &b[0], strlen(b)));
    }
    return 0;
}