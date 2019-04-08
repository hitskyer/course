#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct contest
{
	string Sname;
	int FinishNum;
	int Penaltypoints;
};

int main()
{
	int TeamNum;
	queue<contest> que;
	int SubTimes;
	int nConsumeTime;
	contest temp;
	cin >> TeamNum;
	while(TeamNum--)
	{
		temp.Sname.clear();
		temp.Penaltypoints = temp.FinishNum = 0;
		cin >> temp.Sname;
		for(int i = 0;i< 4; ++i)
		{
			cin >> SubTimes;
			cin >> nConsumeTime;
			if(nConsumeTime)
			{
				temp.FinishNum += 1;
				temp.Penaltypoints += (nConsumeTime + (SubTimes -1)*20);
			}
		}
		if(!que.empty())
		{
			if(que.front().FinishNum < temp.FinishNum)
			{
				que.pop();
				que.push(temp);
			}
			else if(que.front().FinishNum == temp.FinishNum 
				&& que.front().Penaltypoints > temp.Penaltypoints)
			{
				que.pop();
				que.push(temp);
			}
			else if(que.front().FinishNum == temp.FinishNum 
				&& que.front().Penaltypoints == temp.Penaltypoints)
			{
				que.push(temp);
			}
			else
				continue;
		}
		else
			que.push(temp);	
	}
	while(!que.empty())
	{
		cout << que.front().Sname.c_str() 
			 << " " << que.front().FinishNum << " " << que.front().Penaltypoints << endl;
		que.pop();
	}
	return 0;
}