#include <iostream>
#include <limits>
using namespace std;

long out_main;
int main() {
	cout << "the size of long is " << sizeof(long) << " bytes" << endl;

	long in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for long is " << (numeric_limits<long>::max)() << endl;
	long a = (numeric_limits<long>::max)() + 1;
	cout << "max for long + 1 is " << a << endl;

	cout << "min for long is " << (numeric_limits<long>::min)() << endl;
	long b = (numeric_limits<long>::min)() - 1;
	cout << "min for long - 1 is " << b << endl;

	return 0;
}
