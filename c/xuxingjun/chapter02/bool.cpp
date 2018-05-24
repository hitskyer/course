#include <iostream>
using namespace std;

bool out_main;
int main() {
	cout << "the size of bool is " << sizeof(bool) << " bytes" << endl;
	bool in_main;
	cout << "out_main = " << out_main << "(0, every time)" << endl;
	cout << "in_main = " << in_main << "(0 or 1, not sure)" << endl;

	bool b;
	// 输出并不确定
	cout << "b = " << b << " int(b) = " << int(b) << "(after bool b)" << endl;
	b = 1;
	cout << "b = " << b << " int(b) = " << int(b) << "(after b = 1)" << endl;
	b = 2;
	// 对布尔值，非0都被视为1(true)
	cout << "b = " << b << " int(b) = " << int(b) << "(after b = 2)" << endl;
	b = true;
	cout << "b = " << b << " int(b) = " << int(b) << "(after b = true)"<< endl;
	b = false;
	cout << "b = " << b << " int(b) = " << int(b) << "(after b = false)" << endl;

	return 0;
}
