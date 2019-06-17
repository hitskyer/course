/**
 * @description: 2维字符串匹配
 * @author: michael ming
 * @date: 2019/6/18 0:07
 * @modified by: 
 */
#include <iostream>
#define nr 5
#define nc 5
#define mr 2
#define mc 2
int cal_hash_t(int* table, int r, int c, char ch[][mc])
{
    int i, j, value = 0;
    for (i = 0; i < r; ++i) //计算2d模式串的hash值value
    {
        for(j = 0; j < c; ++j)
            value += table[ch[i][j]-'a'];
    }
    return value;
}
int cal_hash_s_child(int* table, int i0, int j0, int r, int c, char ch[][nc])
{
    int i, j, hash_value = 0;
    for (i = i0; i < r; ++i) //计算2d子串的hash值value
    {
        for(j = j0; j < c; ++j)
            hash_value += table[ch[i][j]-'a'];
    }
    return hash_value;
}
bool same(char s[][nc], char t[][mc], int i0, int j0)
{
    int x = i0, y = j0, i, j;
    for(i = 0; i < mr; ++i,++x)
    {
        for(j = 0, y = j0; j < mc; ++j,++y)//记得写y=j0,换行后y复位
        {
            if(s[x][y] != t[i][j])
                return false;
        }
    }
    return true;
}
bool str_RK_2d(char s[][nc], char t[][mc])//s是主串，t是模式串
{
    int table[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                     47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};//质数表对应a-z
    int i, j, hash_val, value;
    value = cal_hash_t(table,mr,mc,t);//计算2d模式串哈希值
    for(i = 0; i < nr-mr+1; ++i)//行最多nr-mr+1次比较
    {
        for(j = 0; j < nc-mc+i; ++j)//列最多nc-mc+1次比较
        {
            hash_val = cal_hash_s_child(table,i,j,mr+i,mc+j,s);//计算2d子串哈希值
            if(hash_val == value && same(s,t,i,j))
            {//如果2d子串哈希值等于模式串的，且"真的"字符串匹配（避免冲突带来的假匹配）
                std::cout << "找到模式矩阵，其左上角在 " << i+1 << " 行，" << j+1 << " 列." << std::endl;
                return true;
            }
        }
    }
    return false;

}

int main()
{
    char s[  ][nc] = {{ 'a', 'b', 'a', 'b', 'a' },
                      { 'a', 'b', 'a', 'b', 'a' },
                      { 'a', 'b', 'b', 'a', 'a' },
                      { 'a', 'b', 'a', 'a', 'b' },
                      { 'b', 'b', 'a', 'b', 'a' }};
    char t[  ][mc] = {{ 'a', 'b' },
                      { 'b', 'a' }};
    str_RK_2d(s,t);
    char a[  ][nc] = {{ 'd', 'a', 'b', 'c' },
                      { 'e', 'f', 'a', 'd' },
                      { 'c', 'c', 'a', 'f' },
                      { 'd', 'e', 'f', 'c' },
                      { 'b', 'b', 'a', 'b' }};
    char b[  ][mc] = {{ 'c', 'a' },
                      { 'e', 'f' }};
    str_RK_2d(a,b);
    return 0;
}