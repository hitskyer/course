#include <iostream>
using namespace std;
void myswap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	cout << "enter two numbers : " << endl;
	int x, y;
	cin >> x >> y;
	cout << "values    before exchanging : " << x << " " << y << endl;
	cout << "addresses before exchanging : " << &x << " " << &y << endl;
	myswap(&x, &y);
	cout << "values    after exchanging : " << x << " " << y << endl;
	cout << "addresses after exchanging : " << &x << " " << &y << endl;
	return 0;
}
