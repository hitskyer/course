#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> v1, v(5);
	vector<int> v3(5,6);
	vector<int> v4(v3);
	vector<string> v5(2,"hello");
	cout<<"the size of v5 is :"<<v5.size()<<endl;
	cout<<"the size of v is :"<<v.size()<<endl;
	cout<<(v1.empty())<<endl;
//	v=v3.push_back(9);
	for(vector<int>::size_type ix =0;ix != v3.size();ix++)
	{
		v3[ix]=ix;
		cout<<ix<<" ";
	}
	cout<<endl;
	int x= 0;
	for(vector<int>::iterator ite =v4.begin();ite !=v4.end();ite++)
	{
		*ite=x;
		x++;
		cout<<*ite<<" ";
	}
	cout<<endl;
	return 0;
}
