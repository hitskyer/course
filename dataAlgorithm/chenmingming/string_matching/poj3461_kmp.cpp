#include <string>
#include <stdio.h>
#include <iostream>
int next[10001];
char a[1000001], b[10001];
void calNexts(char *b, int m, int *next)
{
    next[0] = -1;
    int j = 0, k = -1;
    while(j < m)
    {
        if(k == -1 || b[j] == b[k])
        {
            j++;k++;
//            if(j != m)//最后一个位置越界
                next[j] = k;
        }
        else
            k = next[k];
    }
}
int str_kmp(char *a, int n, char *b, int m)
{
    calNexts(b, m, next);
    int i = 0, j = 0, times = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j])
        {
            i++;j++;
        }
        else
        {
            j = next[j];
        }
        if(j == m)
        {
            times++;
            j = next[j];
        }
    }
    return times;
}
int main()
{
    char ch;
    int count, len_a, len_b;
    std::cin >> count;
    while(count--)
    {
        len_a = len_b = 0;
        ch = getchar();
        while(ch == ' '||ch == '\n')
            ch = getchar();
        while(ch != '\n')
        {
            b[len_b++] = ch;
            ch = getchar();
        }
        ch = getchar();
        while(ch != '\n')
        {
            a[len_a++] = ch;
            ch = getchar();
        }
        printf("%d\n",str_kmp(a,len_a, b,len_b));
    }
    return 0;
}