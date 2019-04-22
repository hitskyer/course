/*
* Copyright: (c) 2019
*
* 文件名称:  POJ1442.cpp 
* 文件标识：
* 摘	要： 优先队列
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/16  13:29
*/

/*
分析：因为输出时是按照先输出最小的，再输出第二小这样的方式输出的，相当于依次输出一个有序序列中的值。
但因为这个序列不是固定不变的，而是不断的在更新，所以用数组是无法实现的。我们可以用优先队列来做。

定义两个优先队列，一个用来存储前k小的数，大数在前，小数在后；另一个优先队列第k+1小到最大的数，
小数在前，大数在后。每次拿到一个数，先判断第一个优先队列中的数满不满k个，如果不满k个，
则直接把这个数压入到第一个队列；如果满k个，判断这个数和第一个优先队列中的第一个数的大小：
如果比第一个数大，就压入第二个优先队列；如果比第一个数小，就把第一个优先队列的队首元素弹出压入第二个队列，
把这个新数压入第一个优先队列。
输出时，如果第一个优先队列里的元素个数小于k，则先把第二个优先队列里的队首元素弹出压入第一个优先队列，
然后输出第一个优先队列的队首元素；如果满k个，则直接输出第一个优先队列的队首元素。

*/
//#include<cstdio>
//#include<queue>
//using namespace std;
//int a[30010], u[30010];
//
//int main()
//{
//	int n, m, i, j, k, x, ans;
//	while(~scanf("%d%d",&m,&n))
//	{	
//		priority_queue<int, vector<int>, less<int> > que1;  //队列中的元素从大到小排序
//		priority_queue<int, vector<int>, greater<int> > que2;   //队列中的元素从小到大排序
//		for(i = 1; i <= m; i++)
//			scanf("%d",&a[i]);
//		for(j = 1; j <= n; j++)
//			scanf("%d",&u[j]);
//		i = 0;
//		j = k = 1;
//		while(j <= n)
//		{
//			if(i == u[j])  //弹出第k小的数
//			{
//				j++;
//				if(que1.size() < k) //que1里的元素不够k个
//				{
//					x = que2.top();
//					que1.push(x);
//					que2.pop();
//				}
//				ans = que1.top(); 
//				printf("%d\n",ans);
//				k++;  //每次弹出一个数后，k的值都要加1
//			}
//			else
//			{
//				i++;
//				//que1里的元素不够k个
//				if(que1.size() < k) 
//				{
//					que2.push(a[i]); 
//					x = que2.top();	
//					que2.pop();
//					que1.push(x);  //先把a[i]压入que2，再从que2里取出最小值，压入que1
//				}
//				//如果que1的元素达到k个，且要压入队列的值比que1中的当前最大值大，说明que1中当前的最大值并不是第k小
//				else if(que1.top() > a[i])
//				{ 
//					x = que1.top();
//					que1.pop();
//					que2.push(x);
//					que1.push(a[i]);
//				}
//				//que1中的元素个数达到k个，且要压入队列的值比que1中的当前最大值小，说明que1中当前的最大值就是是第k小，则把a[i]直接压入que2中
//				else
//				{
//					que2.push(a[i]);
//				}
//			}
//		}
//	}
//	return 0;
//
//}

#include <stdio.h>
#include <queue>
using namespace std;
int data[30001];
int command[30000];
int main()
{
	int AddNum = 0;
	int GetNum = 0;
	scanf_s("%d%d", &AddNum, &GetNum);
	priority_queue<int, vector<int>, less<int> > bigque;
	priority_queue<int, vector<int>, greater<int> > smallque;
	for(int i = 0; i < AddNum; ++i)
	{
		scanf_s("%d", &data[i]);
	}
	for(int j = 0; j < GetNum; ++j)
	{
		scanf_s("%d", &command[j]);
	}
	int i = 0;
	int j = 0;
	size_t k = 1;
	int x = 0;
	while(j < GetNum)
	{
		if(i == command[j])
		{
			if(bigque.size() < k)
			{
				x = smallque.top();
				bigque.push(x);
				smallque.pop();
			}
			printf("%d\n", bigque.top());
			k++;
			j++;
		}
		else
		{
			if(bigque.size() < k)
			{
				smallque.push(data[i]);
				x = smallque.top();
				smallque.pop();
				bigque.push(x);
			}
			else if(bigque.top() > data[i])
			{
				x = bigque.top();
				bigque.pop();
				smallque.push(x);
				bigque.push(data[i]);
			}
			else
				smallque.push(data[i]);
			i++;
		}
	}

	return 0;
}