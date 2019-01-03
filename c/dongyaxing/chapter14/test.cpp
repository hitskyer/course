#include <iostream>
using namespace std;

int Add(int *a, int *b)
{
	*a += *b;
	return *a;
}

int main()
{
	int a = 10, b= 5;
	cout << Add(&a,&b) << endl;
	return 0;
}
