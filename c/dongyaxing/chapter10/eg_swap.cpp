#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10,11};
	vector<int> iveca(a,a+5);
	vector<int> ivecb(b,b+6);
	
	iveca.swap(ivecb);	
	vector<int>::iterator itera=iveca.begin();
	vector<int>::iterator iterb=ivecb.begin();
	
	cout<<"交换a与b ，输出："<<endl;
	for(;itera != iveca.end(); ++itera)
	{
		cout<<*itera<<",";
	}
	cout<<endl;
	for(;iterb != ivecb.end(); ++iterb)
	{
		cout<<*iterb<<",";
	}
	cout<<endl;
	
	return 0;
}
