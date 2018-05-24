#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cout << "enter a string :" << endl;
	cin >> s;
	char *c = new char[strlen(s.c_str())];
	strcpy(c,s.c_str());
	c[strlen(s.c_str())+1] ='\0';
	cout << "char is " << c << endl;
	delete [] c;
	return 0;
}
