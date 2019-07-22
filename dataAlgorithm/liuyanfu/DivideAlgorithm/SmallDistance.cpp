#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct point
{
	double x;
	double y;
};

bool sortBy_x(point& point1, point& point2)
{
	if(point1.x == point2.x)
		return point1.y < point2.y;
	return point1.x < point2.x;
}

bool sortBy_y(point& point1, point& point2)
{
	return point1.y < point2.y;
}

double getDistance(point& point1, point& point2)
{
	double dis_x = point1.x - point2.x;
	double dis_y = point1.y - point2.y;
	return sqrt(dis_x*dis_x + dis_y*dis_y);
}

double getMin(vector<point>& vec, int low, int high)
{
	if(high - low == 1)
	{
		return getDistance(vec[low], vec[low + 1]);
	}
	else if(high - low == 2)
	{
		double dist1 = getDistance(vec[low], vec[low + 1]);
		double dist2 = getDistance(vec[low], vec[low + 2]);
		double dist3 = getDistance(vect[low + 1], vec[low + 2]);
		return min(min(dist1, dist2), dist3);
	}
	else
	{
		int mid = (low + high) / 2;
		double left_min = getMin(vec, low, mid);
		double right_min = getMin(vec, mid + 1, high]);
		double d = min(left_min, right_min);
		vector<point> res;
		res.erase(res.begin(), res.end());
		int i, j, k = 0;
		for(i = low; i <= high; ++i)
		{
			if(abs(vec[i].x - vec[mid].x) < d)
				res.push_back(vec[i]);
		}
		sort(res.begin(), res.end(), sortBy_y);
		for(i = 0; i < res.size() - 1; ++i)
		{
			for(j = i + 1; j < res.size(); ++j)
			{
				if(res[j].y - res[i] >= d)
					break;
				double dp = getDistance(res[i], res[j]);
				if(dp < d)
				{
					d = dp;
				}
			}
		}
		return d;
	}
}


int main()
{
	int i, j, n;
	cin >> n;
	vector<point> vec;
	for(i = 0; i < n; ++i)
	{
		point point1;
		cin >> point1.x >> point1.y;
		vec.push_back(point1);
	}
	sort(vec.begin(), vec.end(), sortBy_x);
	cout << "所有点之间的最短距离为：" << getMin(vec, 0, vec.size() - 1) << endl;
	return 0;
}