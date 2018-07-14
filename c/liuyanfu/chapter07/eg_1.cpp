#include <iostream>
using namespace std;

int gcd(int v1,int v2)
{
	while(v2)
	{
		int temp = v2;
		    v2   = v1 % v2;
		    v1   = temp;
	}
	return v1;
}
int main()
{
	cout << "pleased input two int numbers:" << endl;
	int a = 0;
	int b = 0;
	cin >> a >> b ;
	cout << endl;
	int c=gcd (a,b);
	cout << a << "  and  "<< b << "  greatest common divisor  " << c << endl;
	return 0;
}
