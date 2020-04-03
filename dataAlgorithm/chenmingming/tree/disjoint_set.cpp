/**
 * @Description: 并查集
 * @Author: michael ming
 * @Date: 2020/4/3 16:14
 * @Modified by: 
 * @Website: https://michael.blog.csdn.net/
 */
#include<bits/stdc++.h>
using namespace std;
const int n = 10;
int father[n] = {0,1,2,3,4,5,6,7,8,9};
void init()
{
    for(int i = 0; i < n; i++)
        father[i] = i;
};
int uniFind(int x)
{
    if(x == father[x])
        return x;
    return father[x] = uniFind(father[x]);//等式为路径压缩操作
}
void merge(int x, int y)
{
    int fatherx = uniFind(x);
    int fathery = uniFind(y);
    if(fatherx != fathery)
        father[fatherx] = fathery;
}
int main()
{
    init();
    merge(1,2);
    cout << "1的代表" << uniFind(1) << endl;
    cout << "2的代表" << uniFind(2) << endl;
    cout << "0的代表" << uniFind(0) << endl;
    merge(0,1);
    cout << "0的代表" << uniFind(0) << endl;
    return 0;
}