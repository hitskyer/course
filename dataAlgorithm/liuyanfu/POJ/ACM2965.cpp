#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int map[4][4];
int ans = 17;

struct Point
{
	int x;
	int y;
	Point(int r, int c)
	{
		x = r;
		y = c;
	}
};

vector<Point> vec;
vector<Point> ret;

bool isOpen()
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if(0 != map[i][j])
				return false;
		}
	}
	return true;
}


void flip(int x, int y)
{
	map[x][y] = !map[x][y];
	for(int i = 0; i< 4; ++i)
	{
		if(i == y) continue;
		map[x][i] = !map[x][i];
	}
	for(int j = 0; j < 4; ++j)
	{
		if(j == x)continue;
		map[j][y] = !map[j][y];
	}
}


void entryData()
{
	char ch;
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j <4; ++j)
		{
			cin >> ch;
			if(ch == '+')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
}


void dfs(int x, int y, int curStep)
{
	if(isOpen())
	{
		ans = min(curStep, ans);
		ret.assign(vec.begin(), vec.end());
		return;
	}
	if(x == 4 || y == 4)
		return;
	int newy = (y+1)%4;
	int newx = x+(y+1)/4;
	dfs(newx, newy, curStep);
	flip(x, y);
	vec.push_back(Point(x+1,y+1));
	dfs(newx, newy, curStep + 1);
	flip(x, y);
	vec.pop_back();
}


int main()
{
	entryData();
	dfs(0,0,0);
	if(ans != 17 && !ret.empty())
	{
		cout << ans << endl;
		for(int i = 0; i < ans; ++i)
		{
			cout << ret[i].x << " " << ret[i].y << endl;
		}
	}

	return 0;
}