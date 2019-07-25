/**
 * @description: 最长递增子序列
 * @author: michael ming
 * @date: 2019/7/25 22:10
 * @modified by: 
 */
#include <iostream>
using namespace std;
//回溯方法
void lis(int *a, int N, int idx, int curLen, int &maxLen)
{
    cout << "idx " << idx << " maxlen " << maxLen << endl;
    if(idx == N)
        return;
    for(int i = idx+1; i < N; ++i)
    {
        if(a[i-1] <= a[i])
//            lis(a,N,i,curLen+1,maxLen);//回溯
            curLen++;//只取上一行或者只留本行
        else
            lis(a,N,i,1,maxLen);
    }
    if(curLen > maxLen)
        maxLen = curLen;
}
int main()
{
    int maxLen = 1;
    const int N = 7;
    int arr[N] = {2,9,3,6,5,1,7};
    lis(arr,N,0,1,maxLen);
    cout << "arr数组最长递增子序列长度（回溯）：" << maxLen << endl;
}