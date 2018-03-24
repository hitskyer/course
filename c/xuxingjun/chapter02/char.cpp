#include <iostream>
using namespace std;

int main() {
	char c;
	for (int i = -128; i < 128; ++i) {
		c = i;
		cout << "i = " << i << ", c = " << c << endl;
	}
	signed char sc;
	for (int i = -128; i < 128; ++i) {
		sc = i;
		cout << "i = " << i << ", sc = " << sc << endl;
	}
	unsigned char uc;
	for (int i = 0; i < 256; ++i) {
		uc = i;
		cout << "i = " << i << ", uc = " << uc << endl;
	}
	return 0;
}
