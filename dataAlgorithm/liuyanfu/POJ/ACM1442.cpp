/*
* Copyright: (c) 2019
*
* 文件名称:  PrioprityQueue.cpp	
* 文件标识：
* 摘	要： 优先队列
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/16  13:29
*/

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> bigque;
priority_queue<int,vector<int>, greater<int> > smallque;

int data[30010];
int command[30000];

int main()
{
	int AddNum = 0;
	int GetNum = 0;
	cin >> AddNum >> GetNum;
	int i = 0;
	int j = 0;
	for(i = 0; i < AddNum; ++i)
	{
		cin >> data[i];
	}
	for(j = 0; j < GetNum; ++j)
	{
		cin >> command[j];
	}
	size_t k = 1;//代表输出第几小的数据
	i = 0;//代表smallque中压入数据的个数
	j = 0;//代表循环次数
	int temp = 0;
	while(j < GetNum)
	{
		if(i == command[j])
		{
			if(bigque.size() < k)
			{
				temp = smallque.top();
				smallque.pop();
				bigque.push(temp);
			}
			while(!smallque.empty() && smallque.top() < bigque.top())
			{
				temp = bigque.top();
				bigque.pop();
				smallque.push(temp);
				temp = smallque.top();
				smallque.pop();
				bigque.push(temp);
			}
			cout << bigque.top() << endl;
			k++;
			++j;
		}
		else
		{
			smallque.push(data[i]);
			++i;
		}	
	}

	return 0;
}