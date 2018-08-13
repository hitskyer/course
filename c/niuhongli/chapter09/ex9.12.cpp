#include<iostream>
#include<vector>
using namespace std;

bool findIn(vector<int>:: iterator beg, vector<int>::iterator end, int iv)
{
	while(beg!=end)
	{
		if(*beg==iv)
			break;
		else
			++beg;
	}
	if(beg!=end)
		return true;
	else 
		return false;
}

int main()
{
	vector<int> ivec;
	int ival;
	cout << "输入元素：" << endl;
	while(cin >> ival)
	{
		ivec.push_back(ival);
		if(cin.get()=='\n')
			break;
	}
	cout << "输入查找的元素: " << endl;
	cin >> ival;
	bool bool_result="true";
	bool_result=findIn(ivec.begin(),ivec.end(),ival);
	if(bool_result)
	{
		cout << "元素被找到了" << endl;
		return 0;
	}
	else
	{ 
		cout << "元素未找到 " << endl;
		return -1;
	}
}
