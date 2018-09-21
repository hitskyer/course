#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string sval, keyval;
	list<string> svec;
	cout << "enter some string: " << endl;
	while(cin >> sval)
		svec.push_back(sval);
	cin.clear();
	cout << "enter the val you want to count: " << endl;
	cin >> keyval;
	cout << count(svec.begin(), svec.end(),keyval)
		<< " elements in the vector have value " << keyval << endl;
	return 0;
}