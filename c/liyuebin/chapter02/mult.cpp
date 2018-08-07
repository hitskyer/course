#include <iostream>
using namespace std;


int multi(int &a,int &b)
{
	return a*b;
}

int main()
{
	int a =10;
	int b =5;
	cout << multi(a,b) << endl;
	return 0;
}
