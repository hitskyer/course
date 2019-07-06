/**
 * @description: n 个硬币中有1枚是假币，假币重量轻，如何快速找出假币
 * @author: michael ming
 * @date: 2019/7/6 20:37
 * @modified by: 
 */
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
int findcoin(int *weight, int left, int right, int &weightimes)
{
    if(left+1 == right)//只有2枚硬币
    {
        weightimes++;//称重比较一次
        if(weight[left] < weight[right])
            return left;//返回重量小的位置
        else
            return right;
    }
    int i, mid, weightsumL, weightsumR;
    weightsumL = weightsumR = 0;
    mid = left + (right-left)/2;
    if((right-left+1)%2 == 0)//偶数枚银币
    {
        weightimes++;
        for(i = left; i <= mid; ++i)
            weightsumL += weight[i];//计算左边重量(计算机没有天平，只能一个个加)
        for(i = mid+1; i <= right; ++i)
            weightsumR += weight[i];//右边重量
        if(weightsumL > weightsumR)//左边重，假币在右边
            return findcoin(weight,mid+1,right,weightimes);
        else if(weightsumL < weightsumR)//假币在左边
            return findcoin(weight,left,mid,weightimes);
        else//假币不在两边（偶数枚银币）
            ;//什么都不做，不必再找了
    }
    else//奇数枚硬币
    {
        weightimes++;
        for(i = left; i <= mid-1; ++i)
            weightsumL += weight[i];//计算左边重量
        for(i = mid+1; i <= right; ++i)
            weightsumR += weight[i];//右边重量
        if(weightsumL > weightsumR)//左边重，假币在右边
            return findcoin(weight,mid+1,right,weightimes);
        else if(weightsumL < weightsumR)//假币在左边
            return findcoin(weight,left,mid-1,weightimes);
        else//两边相等（奇数枚硬币），剩余的那个是假币
            return mid;
    }
}
int main()
{
    srand(unsigned(time(0)));
    int num, i, weightimes = 0;
    cout << "请输入硬币总个数:";
    cin >> num;
    const int coinNum = num;
    int *weight = new int [coinNum];
    for(i = 0; i < coinNum; ++i)
    {
        weight[i] = 10;
    }
    i = rand()%num;
    weight[i] = 9;  //随机生成假币
    for(i = 0; i < coinNum; ++i)//打印硬币信息
    {
        cout << i + 1 << " 硬币重量: " << weight[i] << endl;
    }
    cout << "假硬币是第" << findcoin(weight,0,coinNum-1,weightimes)+1 << "个。" << endl;
    cout << "共称了" << weightimes << "次，找到假币。";
    delete[]weight;
    return 0;
}