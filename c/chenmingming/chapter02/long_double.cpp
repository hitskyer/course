#include <iostream>
#include<cmath>
using namespace std;
long double out_long_double;
int main()
{
	cout << "size of long double is " << sizeof(long double) << " bytes" << endl;
	long double a;
	cout << "uninitialized_inside_long double " << a << endl;
	cout << "uninitialized_inside_long double " << a << endl;

	cout << "uninitialized_outside_long double " << out_long_double << endl;
	cout << "uninitialized_outside_long double " << out_long_double << endl;

	long double max_long_double =pow(2,8*sizeof(long double)-1)-1, min_long_double = -pow(2,8*sizeof(long double)-1);
	
	cout << "max_long double is " << max_long_double << endl
		<< "min_long double is " << min_long_double << endl;

	long double max_add1=max_long_double+1,min_minus1=min_long_double-1;

	cout << "max_long double+1 is " << max_add1 << endl
		<< "min_long double-1 is " << min_minus1 << endl;
	return 0;
}
