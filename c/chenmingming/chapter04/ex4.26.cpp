#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s1;
	cout << "enter string. ";
	cin >> s1;
	cout <<" s1 is "<< s1 <<endl;
	const int sz=100;
	char s2[sz];
	cin >> s2;
//	char *p = s2;
//	for(size_t ix=0;ix!=sz;++ix)
//	{
//		cout << s2[ix];
//	}
	cout <<"s2 is "<< s2 << endl;
	return 0;
}
