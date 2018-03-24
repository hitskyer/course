#include <iostream>
using namespace std;

int main() {
	bool b;
	// 输出并不确定
	cout << "b = " << b << endl;
	b = 1;
	cout << "b = " << b << endl;
	b = 2;
	// 对布尔值，非0都被视为1(true)
	cout << "b = " << b << endl;
	b = true;
	cout << "b = " << b << endl;
	b = false;
	cout << "b = " << b << endl;

	return 0;
}
