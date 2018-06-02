#include<iostream>
#include<vector>
using namespace std;
double f1(vector<double>::iterator begin,vector<double>::size_type n)
{
	double sum = 0;
	for(vector<double>::iterator it = begin;it != begin+n;++it)
	{
		sum += *it;
	}
	return sum;
}

int main()
{
	vector<double> vec;
	cout << "输入一串元素值："<< endl;
	double num;
	while(cin >> num)
	{
		vec.push_back(num);
	}
	cout << "各元素和为：" << f1(vec.begin(),vec.size()) << endl;
	return 0;
}
