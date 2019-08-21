#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const double INF = 1e20;
const int N = 65535;	// 用于申请数组长度为N

struct Point
{
	int x;
	int y;
}point[N];

int n;
int tmpt[N];	// 用于保存距离 mid 为d的长度中的点

// 按照x坐标从小到大排序Point数组
bool cmpxy(const Point &a, const Point &b)
{
	if(a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

// 按照y坐标从小到大排序Point数组
bool cmpy(const int &a, const int &b)
{
	return point[a].y < point[b].y;
}

// 找到小值输出
double min(double a, double b)
{
	return a < b ? a : b;
}

// 求下标为 i和 j的两点的Point，的距离
double dis(int i, int j)
{
	return sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x)
		+ (point[i].y - point[j].y) * (point[i].y - point[j].y));
}

//最近点对距离，递归求解
double Closest_Pair(int left, int right)
{
	double d = INF;
	if(left == right)	// 最后剩下一个点
		return d;
	if(left + 1 == right)	// 最后剩下两个点
		return dis(left, right);
	int mid = (left + right) >> 1;		// /2
	double d1 = Closest_Pair(left, mid);
	double d2 = Closest_Pair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	for(i = left; i <= right; ++i)
	{
		if(abs(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, cmpy);
	for(i = 0; i < k; ++i)
	{
		for(j = i + 1; j < k && point[tmpt[j]].y - point[tmpt[i]].y < d; ++j)
		{
			double d3 = dis(tmpt[i], tmpt[j]);
			if(d > d3)
				d = d3;
		}
	}
	return d;
}

int main()
{
	cout << "请输入数组对数，并依次输入数组对 : " << endl;
	int n;
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			cin >> point[i].x >> point[i].y;
		}
		sort(point, point + n, cmpxy);
		cout << "最近的距离为： "<< Closest_Pair(0, (n - 1)/2) << endl;
		cout << endl;
		cout << "如果继续，请输入需要的数组对数，并输入数组对。否则输入 0，退出程序。" << endl;
	}
	cout << "程序结束！" << endl;
	return 0;
}
