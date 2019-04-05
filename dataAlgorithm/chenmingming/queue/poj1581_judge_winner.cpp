/**
 * @description: poj 1581 judge winner 判断胜者是谁
 * @author: michael ming
 * @date: 2019/4/5 16:00
 * @modified by: 
 */
#include <string>
#include <iostream>
#include <queue>
using namespace std;
class Competitor
{
private:
    string name;        //姓名
    int submitTime[4];  //提交次数
    int penaltyPoint[4];    //罚分
    void cal_solved_and_penalty()   //计算求解题目数量，罚分
    {
        for(int i = 0; i < 4; ++i)
        {
            if(penaltyPoint[i] != 0)
            {
                solved++;
                total_penalty += 20*(submitTime[i]-1) + penaltyPoint[i];
            }
        }
    }
public:
    int total_penalty;  //罚分
    int solved;         //求解题目数量
    Competitor(string &str, int* info):total_penalty(0),solved(0)    //构造函数，传入姓名和数据数组
    {
        name = str;
        for(int i = 0, j = 0; i < 4; ++i, ++j)  //传进来的数组数据赋值给类成员
        {
            submitTime[i] = info[j++];
        }
        for(int i = 0, j = 1; i < 4; ++i, ++j)
        {
            penaltyPoint[i] = info[j++];
        }
        cal_solved_and_penalty();   //计算求解题目数量，罚分
    }
    string getName() const  //获取私有成员值
    {
        return name;
    }
};
bool operator<(const Competitor &a, const Competitor &b)    //操作符
{
    if(a.solved < b.solved)     // "<"为从大到小排列，">"为从小到大到排列
        return true;    //解题数目多的，大先出队
    else if(a.solved > b.solved)
        return false;
    else
    {
        if(a.total_penalty > b.total_penalty)
            return true;    //罚分少的，小的先出队
        else
            return false;
    }
}
int main()
{
    int nums_of_player;     //选手个数
    cin >> nums_of_player;
    priority_queue<Competitor> playerQueue; //选手队列
    int info[8];    //4个题目答题数据
    string name;    //姓名
    for(int i = 0; i < nums_of_player; ++i)
    {
        cin >> name;    //获取姓名
        for(int j = 0; j < 8; ++j)  //获取答题数据
            cin >> info[j];
        Competitor player(name,info);   //根据输入的数据，建立选手类对象
        playerQueue.push(player);       //将对象压入优先队列中（优先队列会按优先级排好序）
    }
    cout << playerQueue.top().getName() << " " << playerQueue.top().solved << " "
            << playerQueue.top().total_penalty << endl;     //打印队首的类对象
    return 0;
}