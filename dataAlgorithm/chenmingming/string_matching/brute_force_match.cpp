/**
 * @description: BF暴力匹配
 * @author: michael ming
 * @date: 2019/6/17 20:11
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
int str_BFM(string s, int pos, string t)
{
    if(s.length()== 0 || t.length() == 0)
        return 0;
    int i = pos - 1, j = 0;
    while(i < s.length() && j < t.length())
    {
        if(s[i] == t[j])
        {
            i++;j++;
        }
        else//字符串匹配失败，主串查找开始位置i+1，模式串从头开始
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= t.length())
        return i-j+1;
    else
        return 0;
}
int main()
{
    string a = "ababcabcacbab", b = "abcac";
    cout << a << "中第一次出现" << b << "的位置是：" << str_BFM(a,1,b) << endl;
    return 0;
}