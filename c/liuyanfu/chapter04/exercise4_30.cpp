#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	const char *p1="hello world";
	const char *p2="my name is Bill";
	size_t len = strlen(p1) + strlen(p2);
	char *p = new char [len+1];
	strcpy (p,p1);
	strcat (p,p2);
	while(*p){
		cout << *p ;
		++p;
	}
	cout << endl;
	string str1="hello world";
	string str2="my name is Bill";
	str1+=str2;
	cout << str1 << endl;
	return 0;
}
