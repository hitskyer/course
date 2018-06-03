#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	const int sz = 100;
	char *s1,*s2;
	s1 = new char[sz];
	s2 = new char[sz];
	if(s1 == NULL || s2 == NULL)
	{
		cout << "内存不够了！" << endl;
		return -1;
	}
	cout << "enter two strings!" << endl;
	cin >> s1 >>s2;
	int result;
	result=strcmp(s1,s2);
	if(result>0)
	cout << "\"" << s1 << "\"" << " is bigger than" << "\"" << s2 << "\"" <<endl;
	else if(result<0)
	cout << "\"" << s2 << "\"" << " is bigger than" << "\"" << s1 << "\"" <<endl;
	else
	cout << "s1 and s2 are equal!" <<endl;
	delete[]s1;
	delete[]s2;
	return 0;
}
