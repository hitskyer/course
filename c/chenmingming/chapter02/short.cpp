#include <iostream>
#include<cmath>
using namespace std;
short out_short;
int main()
{
	cout << "size of short is " << sizeof(short) << " bytes" << endl;
	short a;
	cout << "uninitialized_inside_short " << a << endl;
	cout << "uninitialized_inside_short " << a << endl;

	cout << "uninitialized_outside_short " << out_short << endl;
	cout << "uninitialized_outside_short " << out_short << endl;

	short max_short =pow(2,8*sizeof(short)-1)-1, min_short = -pow(2,8*sizeof(short)-1);
	
	cout << "max_short is " << max_short << endl
		<< "min_short is " << min_short << endl;

	short max_add1=max_short+1,min_minus1=min_short-1;

	cout << "max_short+1 is " << max_add1 << endl
		<< "min_short-1 is " << min_minus1 << endl;
	return 0;
}
