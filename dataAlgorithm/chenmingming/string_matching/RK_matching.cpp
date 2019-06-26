/**
 * @description:RK匹配算法，计算子串哈希值，进行对比
 * @author: michael ming
 * @date: 2019/6/17 22:40
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
bool same(char* a, char* b, int m)
{
    for(int i = 0; i < m; ++i)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}
int str_RK(string s, string t)//s是主串，t是模式串
{
    int n = s.length(), m = t.length();
    int table[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                     47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};//质数表对应a-z
     int i, j, hash_val, value = 0;
     for(i = 0; i < m; ++i) //计算模式串的hash值value
     {
         value += table[t[i]-'a'];
     }
     for(i = 0; i < n-m+1; ++i)//最多n-m+1次比较
     {
         hash_val = 0;
         for(j = i; j < m+i; ++j)//计算第i个子串的哈希值
         {
             hash_val += table[s[j]-'a'];
         }
         if(hash_val == value && same(&s[i],&t[0],m))
         {//如果子串哈希值等于模式串的，且"真的"字符串匹配（避免冲突带来的假匹配）
             return i+1;//返回匹配位置，第i位开始，i从1开始
         }
     }
    return 0;
}
int main()
{
    string a = "ababcabcacbab", b = "abcac";
    cout << a << "中第一次出现" << b << "的位置是：" << str_RK(a,b) << endl;
    return 0;
}