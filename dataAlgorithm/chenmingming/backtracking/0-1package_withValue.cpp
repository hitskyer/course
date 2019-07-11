/**
 * @description: 
 * @author: michael ming
 * @date: 2019/7/11 20:42
 * @modified by: 
 */

#include <iostream>
#define MaxWeight 50   //背包承载极限
using namespace std;
void fill(int i, int curWeight, int curValue, int *bag,int *value, int N, int &weightinbag, int &maxValue)
{
    if(curWeight == MaxWeight || i == N)//到达极限了，或者考察完所有物品了
    {
        if(curValue > maxValue)
        {
            maxValue = curValue;//记录历史最大价值
            weightinbag = curWeight;//记录最大价值对应的重量
        }
        return;
    }
    fill(i+1,curWeight,curValue,bag,value,N,weightinbag,maxValue);//不选择当前i物品，cw,cv不更新
    if(curWeight+bag[i] <= MaxWeight)//选择当前i物品，cw,cv更新
    {//没有达到极限，继续装
        fill(i+1,curWeight+bag[i],curValue+value[i],bag,value,N,weightinbag,maxValue);
    }
}
int main()
{
    const int N = 4;
    int bag[N] = {15,6,40,21};
    int value[N] = {1,2,3,4};
    int weightinbag = 0, maxValue = 0;
    fill(0,0,0,bag,value,N,weightinbag,maxValue);
    cout << "最大可装进背包的最大价值是：" << maxValue
            << " ,对应重量是: " << weightinbag;
    return 0;
}