#include <iostream>
#include <limits>
using namespace std;

long long out_main;
int main() {
	cout << "the size of long long is " << sizeof(long long) << " bytes" << endl;

	long long in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for long long is " << (numeric_limits<long long>::max)() << endl;
	long long a = (numeric_limits<long long>::max)() + 1;
	cout << "max for long long + 1 is " << a << endl;

	cout << "min for long long is " << (numeric_limits<long long>::min)() << endl;
	long long b = (numeric_limits<long long>::min)() - 1;
	cout << "min for long long - 1 is " << b << endl;

	return 0;
}
