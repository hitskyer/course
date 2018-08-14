#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	str.reserve(100);
	char a;
	cout << "Enter char to string: " << endl;
	while(cin >> a)
		str.push_back(a);
	cout << "Output the elements in string: " << endl;
	for(string::iterator iter=str.begin();iter!=str.end();++iter)
		cout << *iter << " ";
	return 0;
}
