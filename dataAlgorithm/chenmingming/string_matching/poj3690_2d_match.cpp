/**
 * @description: poj3690 2维矩阵匹配
 * @author: michael ming
 * @date: 2019/6/25 19:47
 * @modified by:
 */
#include <time.h>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
int a[1001][1001];
int b[51][51];
ull hash_b[51];//存放每行的哈希值，每行相当于一个2进制数
ull hash_a[1001][1001];//存放主串子串的哈希值

void cal_hash_b(int r, int c, int b[][51])
{
    int i, j, k;
    ull value;
    for (i = 0; i < r; ++i) //计算2d模式串的hash值value
    {
        value = 0;
        for(j = 0, k = c-1; j < c; ++j,--k)
        {
            value += b[i][j]<<k;
        }
        hash_b[i] = value;
    }
    return;
}
void cal_hash_a_child(int N, int M, int a[][1001], int P, int Q)
{
    int i, j, k, x;
    ull hash_value;
    for (i = 0; i < N; ++i) //计算2d子串的每行的hash值
    {
        for(j = 0; j < M-Q+1; ++j)
        {
            if(j == 0)
            {
                hash_value = 0;
                for(x = j, k = Q-1; x < j+Q && k >= 0; ++x,--k)
                    hash_value += a[i][x]<<k;
            }
            else
                hash_value = ((hash_a[i][j-1]-(a[i][j-1]<<(Q-1)))<<1)+a[i][j+Q-1];
            hash_a[i][j] = hash_value;
        }
    }
}

int str_RK_2d(int a[][1001], int N, int M, int b[][51], int P, int Q)//s是主串，t是模式串
{
    int i, j, k, x;
    bool flag = false;
    cal_hash_b(P,Q,b);//计算2d模式串每行哈希值
    for(j = 0; j < M-Q+1; ++j)//列最多nc-mc+1次比较,分别比较每行，列先固定
    {
        for(i = 0; i < N-P+1; ++i)
        {//行最多nr-mr+1次比较,一组比较P行
            for(x = i, k = 0; x < j+Q && k < Q; ++x,++k)
            {
                if(hash_a[x][j] == hash_b[k])//比较子串哈希值
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return 1;
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
//    clock_t start, finish;
//    start = clock();
    int N, M, T, P, Q, count, ID = 1;
    while(cin >> N >> M >> T >> P >> Q && N)
    {
        count = 0;
        creatMatrix_a(a,N,M);
        cal_hash_a_child(N,M,a,P,Q);
        while(T--)
        {
            creatMatrix_b(b,P,Q);
            count += str_RK_2d(a,N,M,b,P,Q);
        }
        cout << "Case " << ID++ << ": " << count << endl;
    }
//    finish = clock();
//    cout << "takes "<< finish-start << " ms." << endl;
    return 0;
}