#include<iostream>
#include<cstring>
using namespace std;
int main()
{
//	const char ca[]={'h','e','l','l','o'};
	const char ca[]={'h','e','l','l','o','\0'};
	const char *p1 ="some value";
	const char *p = ca;
	cout << "p+4= " << p+4 << endl;
	cout << "p1= " << p1 << endl;
	while(*p)
	{
		cout << *p << endl;
		++p;
	}
	while(*p1)
	{
		cout << *p1 << endl;
		++p1;
	}
	cout << strlen(ca) << endl;
	return 0;
}
