#include <iostream>
#include<cmath>
using namespace std;
float out_float;
int main()
{
	cout << "size of float is " << sizeof(float) << " bytes" << endl;
	float a;
	cout << "uninitialized_inside_float " << a << endl;
	cout << "uninitialized_inside_float " << a << endl;

	cout << "uninitialized_outside_float " << out_float << endl;
	cout << "uninitialized_outside_float " << out_float << endl;

	float max_float =pow(2,8*sizeof(float)-1)-1, min_float = -pow(2,8*sizeof(float)-1);
	
	cout << "max_float is " << max_float << endl
		<< "min_float is " << min_float << endl;

	float max_add1=max_float+1,min_minus1=min_float-1;

	cout << "max_float+1 is " << max_add1 << endl
		<< "min_float-1 is " << min_minus1 << endl;
	return 0;
}
