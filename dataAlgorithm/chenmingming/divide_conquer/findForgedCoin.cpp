/**
 * @description: n 个硬币中有1枚是假币，假币重量轻，如何快速找出假币
 * @author: michael ming
 * @date: 2019/7/6 20:37
 * @modified by: 
 */
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(unsigned(time(0)));
    int num, i;
    cout << "请输入硬币总个数:";
    cin >> num;
    const int coinNum = num;
    int weight[coinNum];
    for(i = 0; i < coinNum; ++i)
    {
        weight[i] = 10;
    }
    i = rand()/RAND_MAX*(num);
    weight[i] = 9;  //随机生成假币
    return 0;
}