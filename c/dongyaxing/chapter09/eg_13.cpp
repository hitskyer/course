#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool findInt(vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	while(beg!=end)
	{
		if(*beg == ival)
			break;
		else
			++beg;
	}
	if(beg != end)
		return true;
	else
		return false;
}

vector<int>::iterator FindInt(vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	while(beg != end)
	{
		if(*beg == ival)
		{
			break;
		}
		else
			++ beg;
	}
	return beg;
}

template<typename T1, typename T2>
T1 FindValue(T1 beg, T1 end, T2 val)
{
	while(beg != end)
	{
		if(*beg == val)
			break;
		else
			++beg;
	}
	return beg;
}

int main()
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ivec(ia, ia+10);
	cout<<"请输入一个数（个位），判断此数是否在vector中"<< endl;
	int ival;
	bool b;
	cin >> ival;
	
	vector<int>::iterator it;
	//it = FindInt(ivec.begin(), ivec.end(), ival);
	b = findInt(ivec.begin(),ivec.end(),ival);
	it = FindValue(ivec.begin(), ivec.end(), ival);
	if(it != ivec.end())
	{	
		cout<<b<<endl;
		cout<< ival <<" is an element of the vector."<< endl;
	}
	else
	{	
		cout<<b<<endl;
		cout<< ival <<" is not an element of the vector."<< endl;
	}
	return 0;
}




