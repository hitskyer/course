/**
 * @description: poj2259 团队排队问题
 * @author: michael ming
 * @date: 2019/4/5 11:24
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define MAX 1001
#define MAX_PEOPLE 1000001

queue<int> team[MAX]; //team[i]代表一个团队队列
queue<int> mainQueue;   //宏观主队列,存储teamIndex值
bool teamInQueue[MAX];  //队伍是否排在主队列中
//memset(teamInQueue, false, sizeof(teamInQueue));
int people[MAX_PEOPLE]; //存储人的队伍teamIndex编号
int teamNums, Scenario=1;
void init()  //每次进入下一次任务时，清空前一次的记录
{
    for(int i = 0; i < teamNums; ++i)  //队列清空
    {
        teamInQueue[i] = false;
        while(!team[i].empty())
            team[i].pop();
    }
    while(!mainQueue.empty())
        mainQueue.pop();
}
void input()
{
    int totalPeopleInTeam,peopleID;
    for(int teamIndex = 0; teamIndex < teamNums; ++teamIndex)
    {
        cin >> totalPeopleInTeam;
        for(int j = 0; j < totalPeopleInTeam; ++j)
        {
            cin >> peopleID;
            people[peopleID] = teamIndex;
            //把每个人的ID（数组中的位置）与其值（组号）建立映射
        }
    }
}
void solve()
{
    int peopleID,teamID;
    string command;
    cout << "Scenario #" << Scenario++ << endl;
    while(cin >> command && command[0] != 'S')  //STOP停止
    {
        if (command[0] == 'E')  //ENQUEUE入队
        {
            cin >> peopleID;  //输入ID后查询其组号teamID（即people[peopleID]）
            teamID = people[peopleID];
            if(teamInQueue[teamID]) //组号是否在大队列里呢(初始为false不在)
            {
                team[teamID].push(peopleID);  //找到我的组入组
            }
            else    //我组没人，我是第一个
            {
                teamInQueue[teamID] = true; //我们组终于有人了
                mainQueue.push(teamID);     //我们组的组号排在最后一组
            }
        }
        else   //DEQUEUE出队
        {
            if(!mainQueue.empty())  //大团组必须还有，如果无，则完全没人了
            {
                teamID = mainQueue.front();   //队头是哪个组的呀
                cout << team[teamID].front() << endl; //从相应的组里找到该组的头
                team[teamID].pop();   //打印了，出队
                if(team[teamID].empty())  //这个组空了，都出去了
                {
                    teamInQueue[teamID] = false;  //标记一下
                    mainQueue.pop();    //从大队里删除空组
                }
            }
        }
    }
    cout << endl;
}
int main()
{
    while(cin >> teamNums && teamNums)
    {
        init();
        input();
        solve();
    }
    return 0;
}