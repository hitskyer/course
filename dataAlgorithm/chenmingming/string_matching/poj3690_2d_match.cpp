/**
 * @description: poj3690 2维矩阵匹配
 * @author: michael ming
 * @date: 2019/6/25 19:47
 * @modified by:
 */
#include <time.h>
#include <stdio.h>
typedef unsigned long long ull;
int a[1001][1001];
int b[51][51];
ull hash_b_h[51];//存放每行的哈希值，每行相当于一个2进制数
ull hash_a_h[1001][1001];//存放主串子串行的哈希值
ull hash_a_v[1001][1001];//存放主串子串列的哈希值
void cal_hash_b_h(int r, int c, int b[][51])
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
        hash_b_h[i] = value;
    }
    return;
}
ull cal_hash_b_v(int r, int c, int b[][51])
{
    int i, k;
    ull value = 0;
    for(i = 0, k = r-1; i < r; ++i,--k)
    {
        value += hash_b_h[i]<<k;
    }
    return value;
}
void cal_hash_a_child_h(int N, int M, int a[][1001], int P, int Q)
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
                hash_value = ((hash_a_h[i][j-1]-(a[i][j-1]<<(Q-1)))<<1)+a[i][j+Q-1];
            hash_a_h[i][j] = hash_value;
        }
    }
}
void cal_hash_a_child_v(int N, int M, int a[][1001], int P, int Q)
{
    int i, j, k, x;
    ull hash_value;
    for (j = 0; j < M-Q+1; ++j) //计算2d子串的每行的hash值
    {
        for(i = 0; i < N-P+1; ++i)
        {
            if(i == 0)
            {
                hash_value = 0;
                for(x = i, k = P-1; x < i+P && k >= 0; ++x,--k)
                    hash_value += hash_a_h[x][j]<<k;
            }
            else
                hash_value = ((hash_a_v[i-1][j]-(hash_a_h[i-1][j]<<(P-1)))<<1) + hash_a_h[i+P-1][j];
            hash_a_v[i][j] = hash_value;
        }
    }
}

int str_RK_2d(int a[][1001], int N, int M, int b[][51], int P, int Q)//s是主串，t是模式串
{
    int i, j;
//    bool flag = false;
    ull hashb;
    cal_hash_b_h(P,Q,b);//计算2d模式串每行哈希值
    hashb = cal_hash_b_v(P,Q,b);
    for(j = 0; j < M-Q+1; ++j)//列最多nc-mc+1次比较,分别比较每行，列先固定
    {
        for(i = 0; i < N-P+1; ++i)
        {//行最多nr-mr+1次比较
            if(hash_a_v[i][j] == hashb)//比较子串哈希值
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
            ch = getchar();
            while(ch == ' '||ch == '\n')
                ch = getchar();
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
            ch = getchar();
            while(ch == ' '||ch == '\n')
                ch = getchar();
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
    while((scanf("%d%d%d%d%d",&N,&M,&T,&P,&Q)!=EOF) && N)
    {
        count = 0;
        creatMatrix_a(a,N,M);
        cal_hash_a_child_h(N,M,a,P,Q);
        cal_hash_a_child_v(N,M,a,P,Q);
        while(T--)
        {
            creatMatrix_b(b,P,Q);
            count += str_RK_2d(a,N,M,b,P,Q);
        }
        printf("Case %d: %d\n",ID++,count);
    }
//    finish = clock();
//    cout << "takes "<< finish-start << " ms." << endl;
    return 0;
}