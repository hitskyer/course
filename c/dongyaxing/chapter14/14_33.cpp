#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GT_cls
{
public:
	GT_cls(int val = 0):bound(val) { }
	bool operator () (const int &ival)
	{
		return ival > bound;
	}
private:
	int bound;
};

int main()
{	
	vector<int> ivec;
	int ival;
	cout<<"enter numbers(ctrl+d to end): "<<endl;
	while(cin>>ival)
	{
		ivec.push_back(ival);
	}
	cin.clear();

	int spval;
	cout<<"enter a specifled value: "<<endl;
	cin>>spval;
	//查找第一个大于指定值得vector元素，返回iter
	vector<int>::iterator iter;
	iter = find_if(ivec.begin(),ivec.end(),GT_cls(spval));

	//输出结果//ivec.end()是最后一个Null 的位置
	if(iter != ivec.end())
	{
		cout<<"the first element that is larger than "<<spval<<" : "<<*iter<<endl;
	}
	else
	{
		cout<<"no element that is larger than "<<spval<<endl;
	}
	return 0;
}
