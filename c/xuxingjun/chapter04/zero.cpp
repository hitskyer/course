#include <iostream>
using namespace std;

int main() {
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *p = ca;
	const char *p1= "some value";
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
