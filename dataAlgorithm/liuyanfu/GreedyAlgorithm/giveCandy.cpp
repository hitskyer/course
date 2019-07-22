#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& d)
{
	for(size_t i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

int candyGiveChild(vector<int>& g, vector<int>& s)
{
	sort(g.begin(), g.end());
	cout << "孩子需求排序后的数组：" << endl;
	print(g);
	sort(s.begin(), s.end());
	cout << "糖果大小排序后的数组：" << endl;
	print(s);
	size_t child = 0;
	size_t cookie = 0;
	while(child < g.size() && cookie < s.size())
	{
		if(g[child] <= s[cookie])
		{
			++child;
		}
		++cookie;
	}
	return child; //返回得到满足的孩子的个数
}


int main()
{
	vector<int> g;
	vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	cout << "孩子需求原数组：" << endl;
	print(g);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);
	cout << "糖果大小原数组：" << endl;
	print(s);
	cout << "有 " << candyGiveChild(g, s) << " 个孩子的糖果愿望能满足" << endl;
	return 0;
}