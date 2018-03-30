#include <iostream>
#include <limits>
using namespace std;

short out_main;
int main() {
	cout << "the size of short is " << sizeof(short) << " bytes" << endl;

	short in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for short is " << (numeric_limits<short>::max)() << endl;
	short a = (numeric_limits<short>::max)() + 1;
	cout << "max for short + 1 is " << a << endl;

	cout << "min for short is " << (numeric_limits<short>::min)() << endl;
	short b = (numeric_limits<short>::min)() - 1;
	cout << "min for short - 1 is " << b << endl;

	return 0;
}
