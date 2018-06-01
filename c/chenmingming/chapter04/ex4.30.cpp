#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	const char *c1 ="good ";
	const char *c2 ="emotion";
	size_t len = strlen(c1) + strlen(c2);
	char *c = new char[len];
	strcpy(c,c1);
	strcat(c,c2);
	cout << c << endl;

	string s1="bad ";
	string s2 = "behavior!";
	string s;
	s=s1+s2;
	cout << s << endl;
}
