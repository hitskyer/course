#include <iostream>
#include <limits>
using namespace std;

long double out_main;
int main() {
	cout << "the size of long double is " << sizeof(long double) << " bytes" << endl;

	long double in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for long double is " << (numeric_limits<long double>::max)() << endl;
	long double a = (numeric_limits<long double>::max)() + (numeric_limits<long double>::max)();
	cout << "max for long double + max for long double is " << a << endl;

	cout << "min for long double is " << (numeric_limits<long double>::min)() << endl;
	long double b = (numeric_limits<long double>::min)() - 1;
	cout << "min for long double - 1 is " << b << endl;

	return 0;
}
