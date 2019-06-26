#include <stdio.h>
#include <iostream>
#include <cstring>
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
    int count;
    std::cin >> count;
    while(count--)
    {
        scanf("%s",&b);
        scanf("%s",&a);
        printf("%d\n",str_kmp(&a[0], strlen(a), &b[0], strlen(b)));
    }
    return 0;
}