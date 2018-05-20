#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s1,s2;
	cout << "enter two strings!" << endl;
	cin >> s1 >>s2;
	if(s1 > s2)
	cout << "\"" << s1 << "\"" << " is bigger than" << "\"" << s2 << "\"" <<endl;
	else if(s1<s2)
	cout << "\"" << s2 << "\"" << " is bigger than" << "\"" << s1 << "\"" <<endl;
	else
	cout << "s1 and s2 are equal!" <<endl;
	return 0;
}
