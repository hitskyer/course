#include<iostream>
using namespace std;
int main()
{
	int max(int,int);
	int (*p)(int,int);
	int a,b,c;
	p=max;
	cout << "enter a,b:"<< endl;
	cin >> a >> b;
	c = (*p)(a,b);
	cout <<"a is "<< a << "b is "<<b << "c is " << c << endl;
}
int max(int x,int y)
{
	int z;
	if(x>y)
		z=x;
	else
		z=y;
	return z;
}
