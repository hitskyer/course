/**
 * @description: 求四个数相加等于0的组合种数
 * @author: michael ming
 * @date: 2019/5/8 22:18
 * @modified by: 
 */
#include <iostream>
using namespace std;
int main()
{
    int line, num;
    cin >> line;
    const int n = line;
    int arr[n][4];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 4; ++j)
            cin >> arr[i][j];
    }

}