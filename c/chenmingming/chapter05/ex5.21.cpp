#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int x;
	vector<int> v1;
	cout << "enter some int num :" << endl;
	while(cin >> x)
	{
		v1.push_back(x);
	}
	for(vector<int>::iterator it = v1.begin(); it != v1.end();++it)
	{
		if((*it)%2 != 0)
			*it *= 2;
		cout << *it << " ";
	}
	return 0;
}

