#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int ival, keyval;
	vector<int> ivec;
	cout << "enter some int val: " << endl;
	while(cin >> ival)
		ivec.push_back(ival);
	cin.clear();
	cout << "enter the val you want to count: " << endl;
	cin >> keyval;
	cout << count(ivec.begin(), ivec.end(),keyval)
		<< " elements in the vector have value " << keyval << endl;
	return 0;
}