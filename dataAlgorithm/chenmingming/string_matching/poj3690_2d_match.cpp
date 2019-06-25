/**
 * @description: poj3690 2维矩阵匹配
 * @author: michael ming
 * @date: 2019/6/25 19:47
 * @modified by: 
 */
#include <iostream>
#include <math.h>
using namespace std;
int a[1001][1001];
int b[51][51];
typedef unsigned long long ull;
ull cal_hash_b(int r, int c, int b[][51])
{
    int i, j, k;
    ull value = 0;
    for (i = 0; i < r; ++i) //计算2d模式串的hash值value
    {
        for(j = 0, k = c-1; j < c; ++j,--k)
        {
            value += b[i][j]*pow(2.0,k);
        }
    }
    return value;
}
ull cal_hash_a_child(int i0, int j0, int r, int c, int a[][1001])
{
    int i, j, k;
    ull hash_value = 0;
    for (i = i0; i < r; ++i) //计算2d子串的hash值value
    {
        for(j = j0, k = c-1; j < c; ++j,--k)
            hash_value += a[i][j]*pow(2.0,k);
    }
    return hash_value;
}
bool same(int a[][1001], int b[][51], int i0, int j0, int mr, int mc)
{
    int x = i0, y = j0, i, j;
    for(i = 0; i < mr; ++i,++x)
    {
        for(j = 0, y = j0; j < mc; ++j,++y)//记得写y=j0,换行后y复位
        {
            if(a[x][y] != b[i][j])
                return false;
        }
    }
    return true;
}
int sum(int a[][1001], int i0, int j0, int mr)
{
    int sum = 0;
    for(int x = 0; x < mr; ++x,++i0)
        sum += a[i0][j0];
    return sum;
}
int str_RK_2d(int a[][1001], int nr, int nc, int b[][51], int mr, int mc)//s是主串，t是模式串
{
    int i, j;
    ull hash_val, value;
    value = cal_hash_b(mr,mc,b);//计算2d模式串哈希值
    for(i = 0; i < nr-mr+1; ++i)//行最多nr-mr+1次比较
    {
        for(j = 0; j < nc-mc+1; ++j)//列最多nc-mc+1次比较
        {
            if(j == 0)
                hash_val = cal_hash_a_child(i,j,mr+i,mc+j,a);//计算2d子串哈希值
            else
                hash_val = (hash_val-pow(2.0,mc-1)*sum(a,i,j,mr))*2 + sum(a,i,j+mc-1,mr);
            if(hash_val == value && same(a,b,i,j,mr,mc))
            {//如果2d子串哈希值等于模式串的，且"真的"字符串匹配（避免冲突带来的假匹配）
                return 1;
            }
        }
    }
    return 0;
}
void creatMatrix_a(int a[][1001], int r, int c)
{
    int i, j;
    char ch;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cin >> ch;
            if(ch == '*')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
}
void creatMatrix_b(int b[][51], int r, int c)
{
    int i, j;
    char ch;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cin >> ch;
            if(ch == '*')
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
}
int main()
{
    int N, M, T, P, Q, count, ID = 1;
    while(cin >> N >> M >> T >> P >> Q && N)
    {
        count = 0;
        creatMatrix_a(a,N,M);
        while(T--)
        {
            creatMatrix_b(b,P,Q);
            count += str_RK_2d(a,N,M,b,P,Q);
        }
        cout << "Case " << ID++ << ": " << count << endl;
    }
    return 0;
}