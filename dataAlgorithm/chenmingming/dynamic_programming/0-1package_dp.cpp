/**
 * @description: 0-1背包--dp应用引入案例
 * @author: michael ming
 * @date: 2019/7/9 1:13
 * @modified by: 
 */
#include <iostream>
#define MaxWeight 9   //背包承载极限
using namespace std;
bool mem [5][9];
int counttimes;
void fill(int i, int curWeight, int *bag, int N, int &maxweightinbag)
{
    cout << "调用次数: " << ++counttimes << endl;
    if(curWeight == MaxWeight || i == N)//到达极限了，或者考察完所有物品了
    {
        if(curWeight > maxweightinbag)
            maxweightinbag = curWeight;//记录历史最大装载量
        return;
    }
    //-----注释掉以下3行查看效果-------
    if(mem[i][curWeight])
        return;
    mem[i][curWeight] = true;
    //---------------------------------
    fill(i+1,curWeight,bag,N,maxweightinbag);//不选择当前i物品，cw不更新
    if(curWeight+bag[i] <= MaxWeight)//选择当前i物品，cw更新
    {//没有达到极限，继续装
        fill(i+1,curWeight+bag[i],bag,N,maxweightinbag);
    }
}
int main()
{
    const int N = 5;
    int bag[N] = {2,2,4,6,3};
    int maxweightinbag = 0;
    fill(0,0,bag,N,maxweightinbag);
    cout << "最大可装进背包的重量是：" << maxweightinbag;
    return 0;
}