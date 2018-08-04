#include <iostream>
using namespace std;

int sub(int &a,int &b)
{
	return a-b;
}

int main()
{
	int a =10;
	int b =5;
	cout << sub(a,b) << endl;
	return 0;
}
