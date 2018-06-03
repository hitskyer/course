#include<iostream>
using namespace std;
int func(int a,const int *p)
{
	return a > *p ? a :*p;
}

int main()
{
	int x,y;
	cin >> x>>y;
	cout<< "较大的数是 " << func(x,&y) << endl;
	return 0;
}
