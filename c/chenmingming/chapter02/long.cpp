#include <iostream>
#include<cmath>
using namespace std;
long out_long;
int main()
{
	cout << "size of long is " << sizeof(long) << " bytes" << endl;
	long a;
	cout << "uninitialized_inside_long " << a << endl;
	cout << "uninitialized_inside_long " << a << endl;

	cout << "uninitialized_outside_long " << out_long << endl;
	cout << "uninitialized_outside_long " << out_long << endl;

	long max_long =pow(2,8*sizeof(long)-1)-1, min_long = -pow(2,8*sizeof(long)-1);
	
	cout << "max_long is " << max_long << endl
		<< "min_long is " << min_long << endl;

	long max_add1=max_long+1,min_minus1=min_long-1;

	cout << "max_long+1 is " << max_add1 << endl
		<< "min_long-1 is " << min_minus1 << endl;
	return 0;
}
