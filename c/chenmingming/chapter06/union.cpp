#include<iostream>
using namespace std;
union test
{
	int i;
	char ch;
	float f;
}name1,name2,name3;

int main()
{
	int x = sizeof(name1);
	cout << x <<endl;
}
