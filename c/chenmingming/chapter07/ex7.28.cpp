#include<iostream>
using namespace std;
int f1(int a)
{
	static int x = 0;
	++x;
	return x;
}

int main()
{
	int i = 0;
	for(;i <10;++i)
	{
		cout << f1(i) << endl;
	}

	return 0;
}
