#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	int n = 0;
	int arr[1000] = {0};
	stack<int> stk;
	while(scanf_s("%d", &n) && n)
	{
		while(scanf_s("%d", &arr[0]) && arr[0])
		{
			for(int i = 1; i < n; ++i)
				scanf_s("%d", &arr[i]);
			int m = 0;
			for(int j = 1; j <= n; ++j)
			{
				stk.push(j);
				while(!stk.empty() && stk.top() == arr[m])
				{
					stk.pop();
					m++;
				}
			}
			printf("%s\n", m == n ? "Yes" : "No");
			while(!stk.empty())
				stk.pop();
		}
		printf("\n");
	}
	return 0;
}
