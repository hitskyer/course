//#include <iostream>
//#include <stack>
//#define max(x,y)	x < y ? y : x
//using namespace std;
//typedef long long DWORD;
//int main()
//{
//	DWORD n, MaxArea, data, nCount, nLen;
//	while(cin >> n && n)
//	{
//		stack<DWORD> stk;
//		MaxArea = 0;
//		for(DWORD i=0; i < n; ++i)
//		{
//			cin >> data;
//			if(stk.empty() || stk.top() <= data)
//				stk.push(data);
//			else
//			{
//				nCount = 1;
//				while(!stk.empty() && stk.top() > data)
//				{
//					if(MaxArea < stk.top()*nCount) 
//						MaxArea = stk.top()*nCount;
//					stk.pop();
//					++nCount;
//				}
//				while(nCount--)
//				{
//					stk.push(data);
//				}
//			}
//		}
//		nLen = stk.size();
//		DWORD num = nLen - 1;
//		while(!stk.empty())
//		{
//			MaxArea = max(MaxArea, stk.top()*(nLen - num));
//			stk.pop();
//			--num;
//		}
//
//		cout << MaxArea << endl;
//	}
//	return 0;
//}


#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 111111;
int n;
long long h[maxn];
int L[maxn], R[maxn];

int main() 
{
	while(scanf_s("%d", &n) && n)
	{
		for(int i =0; i < n; ++i)
		{
			scanf_s("%lld", &h[i]);
		}
		//寻找每个矩形的左端点,即当前高度所在位置的左边第一个低于它的高度，所处的位置
		int temp = 0;
		for(int i=0;i < n;++i)
		{
			temp = i - 1;
			while(temp >= 0 && h[temp] >= h[i])
				temp = L[temp];
			L[i] = temp;
		}
		//寻找每个矩形的右边结点，即当前高度所在位置的右边第一个低于它的高度，所处的位置
		temp = 0;
		for(int i = n - 1; i >=0; --i)
		{
			temp = i + 1;
			while(temp < n && h[temp] >= h[i])
				temp = R[temp];
			R[i] = temp;
		}
		//求矩形的最大面积
		long long maxarea = 0;
		for(int i = 0;i<n;++i)
		{
			maxarea = max(maxarea, h[i]*(R[i] - L[i] - 1));
		}
		printf("%lld\n", maxarea);
	}
	return 0;
}
