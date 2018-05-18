#include <iostream>
using namespace std;

int main() {
	const char *p1= "some value";
	// 选择1
	//const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	// 选择2
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	
	const char *p = ca;
	cout << "p+4 = " << p+4 << endl;
	cout << "p1  = " << p1  << endl;
	while (*p) {
		cout << *p << endl;
		++p;
	}
	while (*p1) {
		cout << *p1 << endl;
		++p1;
	}
	return 0;
}
