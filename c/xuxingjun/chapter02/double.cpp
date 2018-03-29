#include <iostream>
#include <limits>
using namespace std;

double out_main;
int main() {
	cout << "the size of double is " << sizeof(double) << " bytes" << endl;

	double in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for double is " << (numeric_limits<double>::max)() << endl;
	double a = (numeric_limits<double>::max)() + (numeric_limits<double>::max)();
	cout << "max for double + max for double is " << a << endl;

	cout << "min for double is " << (numeric_limits<double>::min)() << endl;
	double b = (numeric_limits<double>::min)() - 1;
	cout << "min for double - 1 is " << b << endl;

	return 0;
}
