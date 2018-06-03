#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr1,arr2;
	bool equal = false;
	int val;
	cout << "enter some numbers for arr1 :" << endl;
	while(cin >> val)
	{
		arr1.push_back(val);
		if(cin.get()=='\n')
			break;
	}
	cout << "enter some numbers for arr2 :" << endl;
	while(cin >> val)
	{
		arr2.push_back(val);
		if(cin.get()=='\n')
			break;
	}
	if(arr1.size() != arr2.size())
	{
		equal = false;
	}
	else if(arr1.size()==0)
		equal = true;
	else
	{
		vector<int>::iterator it1=arr1.begin(),it2=arr2.begin();
		for(;it1 != arr1.end();++it1,++it2)
		{
			if(*it1 != *it2)
			{
				equal = false;
				break;
			}
			else
				equal = true;
		}
	}
	if(equal)
		cout << "2 array equal !" << endl;
		
	else
		cout << "2 array different !" << endl;
	return 0;
}
