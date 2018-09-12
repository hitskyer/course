#include<iostream>
#include<vector>
#include<numeric>
//#include<algorithm>
using namespace std;
int main()
{
	int ival;
	vector<int> ivec;
	cout << "enter some int val: " << endl;
	while(cin >> ival)
		ivec.push_back(ival);
	cout << "sum of int val in vector is " 
		<< accumulate(ivec.begin(), ivec.end(),0) << endl;
	return 0;
}