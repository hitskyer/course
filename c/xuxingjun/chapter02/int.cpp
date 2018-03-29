#include <iostream>
#include <limits>
using namespace std;

int out_main;
int main() {
	cout << "the size of int is " << sizeof(int) << " bytes" << endl;

	int in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(random?)" << endl;

	cout << "max for int is " << (numeric_limits<int>::max)() << endl;
	int a = (numeric_limits<int>::max)() + 1;
	cout << "max for int + 1 is " << a << endl;

	cout << "min for int is " << (numeric_limits<int>::min)() << endl;
	int b = (numeric_limits<int>::min)() - 1;
	cout << "min for int - 1 is " << b << endl;

	return 0;
}
