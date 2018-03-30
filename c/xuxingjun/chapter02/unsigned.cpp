#include <iostream>
#include <limits>
using namespace std;

unsigned out_main;
int main() {
	cout << "the size of unsigned is " << sizeof(unsigned) << " bytes" << endl;

	unsigned in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for unsigned is " << (numeric_limits<unsigned>::max)() << endl;
	unsigned a = (numeric_limits<unsigned>::max)() + 1;
	cout << "max for unsigned + 1 is " << a << endl;

	cout << "min for unsigned is " << (numeric_limits<unsigned>::min)() << endl;
	unsigned b = (numeric_limits<unsigned>::min)() - 1;
	cout << "min for unsigned - 1 is " << b << endl;

	return 0;
}
