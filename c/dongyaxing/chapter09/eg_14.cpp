#include<iostream>
#include<list>
#include<iterator>
#include<string>

using namespace std;

template<typename T1>

T1 output(T1 beg, T1 end)
{
	while(beg != end)
	{
		cout<<*beg<<endl;
	}
}

int main()
{
	list<string> slst;
	string str;
	cout << "Enter some strings (ctrl+D to end): "<< endl;
	while(cin >> str)
	{
		slst.push_back(str);
	}
	list<string>::iterator beg=slst.begin(),end=slst.end();
	output(beg, end);

	int arr[]={1,2,3,4,5,6,7,8,9,0};
	vector<int> ivec(arr, arr+10);
	vector<int>::iterator first=ivec.begin(),last=ivec.end();
	output(first, last);

	//for(list<string>::iterator iter = slst.begin();
	//	iter != slst.end(); ++iter)
	//{
	//	cout << *iter <<endl;
	//}
	return 0;
}
