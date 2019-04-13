/*
团队队列的应用场景，比如在学校里召开大会，要求全校所有学生以班级为单位在操场集合。
这种情况，每个班级在操场上都有自己的队伍。
如果有两个同学小王和小李迟到了一会，其中小王在他们班级的位置找到同学排在了队伍的后边，
而小李在他们班级的位置上并没有看见人（他居然还是他们班第一个来的），那么他就站在班级的位置上作为排头。

*/

#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
int Element[1000000];
char command[10];
int data;

int main()
{
	int teamNum = 0;
	int teamLen = 0;
	int temp = 0;
	int teamNo = 0;
	int nTimes = 1;
	while(scanf_s("%d", &teamNum) && teamNum)
	{
		queue<int> Team[1000];
		queue<int> TeamOrder; 
		for(teamNo = 0; teamNo < teamNum; ++teamNo)
		{
			scanf_s("%d", &teamLen);
			while(teamLen--)
			{
				scanf_s("%d", &temp);
				Element[temp] = teamNo;
			}
		}
		printf("Scenario #%d\n", nTimes++);		
		while(scanf_s("%s", &command, 10) && strncmp(command, "S", 1))
		{
			if(strncmp(command, "E", 1) == 0)
			{
				scanf_s("%d", &data);
				if(Team[Element[data]].empty())
				{
					TeamOrder.push(Element[data]);
				}
				Team[Element[data]].push(data);
			}
			if(strncmp(command, "D", 1) == 0)
			{
				printf("%d\n", Team[TeamOrder.front()].front());
				Team[TeamOrder.front()].pop();
				if(Team[TeamOrder.front()].empty())
					TeamOrder.pop();
			}
		}
		printf("\n");
	}
	return 0;
}