#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	const char *p = "abcdefg";
	int   a = 10;
	string s= "bbbbb";
	const char *c ;
	c=s.c_str();
	string s1="ddeee";
	char *c1 = NULL;
	c1       = (char*)malloc(s1.length()*sizeof(char));
	 s1.copy(c1,s1.length(),0);
	cout << s << endl;
	cout << s1 << endl;
	string paths(p,a);
	return 0;
}
