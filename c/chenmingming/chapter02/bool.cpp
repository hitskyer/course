#include <iostream>
using namespace std;
bool out_bool;
int main()
{
	cout << "size of bool is " << sizeof(bool) << " bytes" << endl;
	bool a;
	cout << "uninitialized_inside_bool " << a << endl;
	cout << "uninitialized_inside_bool " << a << endl;

	cout << "uninitialized_outside_bool " << out_bool << endl;
	cout << "uninitialized_outside_bool " << out_bool << endl;
	bool c=0, d=1, e=2;
	cout << "c is " << c << endl
		<< "d is " << d << endl
		<< "e is " << e << endl;
	cout << "c is " << c << endl
		<< "d is " << d << endl
		<< "e is " << e << endl;
	return 0;
}
