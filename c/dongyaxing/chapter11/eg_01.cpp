#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int count(vector<int> &ivec, int n)
{
	int base = 0;
	for(size_t i = 0; i < ivec.size(); ++i)
	{
		if(ivec[i] == n)
			base++;
	}
	return base;
}

int main()
{
	int arr[] = {3,4,2,6,4,2,5,2,1,2,3,4,5,3,6,4,3};
	vector<int> ivec(arr, arr+17);
	int cnt = 0;
	cnt = count(ivec, 2);
	cout<<"2出现的次数为："<<cnt<<endl;
	
	cout<<"输出vector<int>的和： "<<endl;
	int sum = accumulate(ivec.begin(), ivec.end(), 0);
	cout<<sum<<endl;
	
	cout<<"输出vector<double>的和： "<<endl;
	double darr[] = {1.2, 3.4, 5.6, 7.8, 9.3, 5.4, 3.2, 7.5};
	vector<double> dvec(darr, darr+8);
	int dsum = accumulate(dvec.begin(), dvec.end(),0.1) - 0.1;
	cout<<dsum<<endl;
	return 0;
}
