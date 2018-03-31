#include <iostream>
#include <limits>
using namespace std;

float out_main;
int main() {
	cout << "the size of float is " << sizeof(float) << " bytes" << endl;

	float in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for float is " << (numeric_limits<float>::max)() << endl;
	float a = (numeric_limits<float>::max)() + (numeric_limits<float>::max)();
	cout << "max for float + max for float is " << a << endl;

	cout << "min for float is " << (numeric_limits<float>::min)() << endl;
	float b = (numeric_limits<float>::min)() - 1;
	cout << "min for float - 1 is " << b << endl;

	return 0;
}
