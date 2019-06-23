/**
 * @description: KMP字符串匹配算法
 * @author: michael ming
 * @date: 2019/6/22 17:15
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
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
    for(j = 0; j < m; ++j)//调试代码
        cout << "next[" << j << "] " << next[j] << endl;
}
int str_kmp(char *a, int n, char *b, int m)
{
    int *next = new int [m];
    calNexts(b, m, next);
    int i = 0, j = 0;
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
    }
    if(j == m)
    {
        delete [] next;
        return i-j;
    }
    delete [] next;
    return -1;
}
int main()
{
    string a = "abcacabcbcbaccba", b = "cbaccba";
    cout << a << "中第一次出现" << b << "的位置(从0开始)是：" << str_kmp(&a[0],a.size(),&b[0],b.size());
    return 0;
}