#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	const double a =3;
	double e=1,x,temp;
	int n=0;
	for(x = sqrt(a);e > 0.00000000000000000000000000001;++n)
	{
		temp = x;
		x = sqrt(a+x);
		e = x-temp;
	cout << "limit is " << x << ", n is " << n << ", e is "<< e << endl;
	}
}
