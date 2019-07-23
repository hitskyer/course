#include<iostream>
#include<math.h>
using namespace std;

int map[8][8];
int result[8] = {-1};
int count;
void entryData(int n)
{
	char ch;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> ch;
			if(ch == '#')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
}

bool isOk(int r, int c)
{
	if(!map[r][c])   //如果当前位置不是棋盘位置，则不能放置
		return false;
	while(--r >= 0)		//如果当前列已经放置棋子，则不能放置
	{
		if(result[r] == c)  
			return false;
	}
	return true;
}

void calMethod(int n, int k, int r, int* result)
{
	if(k == 0)
	{
		count++;
		return;
	}
	if(r == n)
	{
		return;
	}
	for(int i = 0; i < n; ++i)
	{
		if(isOk(r, i))
		{
			result[r] = i;
			k--;
			calMethod(n, k, r+1, result);
			result[r] = -1;
			k++;
		}
	}
	calMethod(n, k, r+1, result);
}

int main()
{
	int n, k;	
	while(1)
	{
		cin >> n >> k;
		if(n ==-1 && k == -1)
			break;
		entryData(n);
		count = 0;
		memset(result, -1, sizeof(result));
		calMethod(n, k, 0, result);
		cout << count << endl;
	}
	return 0;
}