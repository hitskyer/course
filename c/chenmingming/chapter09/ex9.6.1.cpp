#include<string>
#include<iostream>
using namespace std;
int main()
{
	char *cp = "Hiya";
	string s1(cp);
	cout << s1 << endl;
	string s6(s1,2);
	cout << s6 <<endl;
}