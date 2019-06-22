/**
 * @description: KMP字符串匹配算法
 * @author: michael ming
 * @date: 2019/6/22 17:15
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
//void calNexts(char *b, int m, int *next)
//{
//    next[0] = -1;
//    int k = -1;
//    for(int i = 1; i < m; ++i)
//    {
//        while(k != -1 && b[k+1] != b[i])
//        {
//            k = next[k];
//        }
//        if(b[k+1] == b[i])
//        {
//            ++k;
//        }
//        next[i] = k;
//    }
//    for(int j = 0; j < m; ++j)//调试代码
//        cout << "next[" << j << "] " << next[j] << endl;
//}
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
    int i, j = 0;
    for(i = 0; i < n; ++i)
    {
        while(j > 0 && a[i] != b[j])
        {
            j = next[j-1] + 1;
        }
        if(a[i] == b[j])
            ++j;
        if(j == m)//找到了匹配的
        {
            delete [] next;
            return i-m+1;
        }
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