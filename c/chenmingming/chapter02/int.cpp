#include <iostream>
#include<cmath>
using namespace std;
int out_int;
int main()
{
	cout << "size of int is " << sizeof(int) << " bytes" << endl;
	int a;
	cout << "uninitialized_inside_int " << a << endl;
	cout << "uninitialized_inside_int " << a << endl;

	cout << "uninitialized_outside_int " << out_int << endl;
	cout << "uninitialized_outside_int " << out_int << endl;

	int max_int =pow(2,8*sizeof(int)-1)-1, min_int = -pow(2,8*sizeof(int)-1);
	
	cout << "max_int is " << max_int << endl
		<< "min_int is " << min_int << endl;

	int max_add1=max_int+1,min_minus1=min_int-1;

	cout << "max_int+1 is " << max_add1 << endl
		<< "min_int-1 is " << min_minus1 << endl;
	return 0;
}
