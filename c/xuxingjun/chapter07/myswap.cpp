#include <iostream>
using namespace std;

void myswap1(int a, int b) 
{
	int tmp = a;
	a       = b;
	b       = tmp;
}
void myswap2(int* a, int* b) 
{
	int tmp = *a;
	*a      = *b;
	*b      = tmp;
}
void myswap3(int* a, int* b) 
{
	int* tmp = a;
	a        = b;
	b        = tmp;
}
int main(int argc, char* argv[]) {
	int a = 1, b = 2;
	cout << "before : a = " << a << " b = " << b << endl;
	myswap1(a, b);
	cout << "after  : a = " << a << " b = " << b << endl;
	cout << endl;

	cout << "before : a = " << a << " b = " << b << endl;
	myswap2(&a, &b);
	cout << "after  : a = " << a << " b = " << b << endl;
	cout << endl;
	
	cout << "before : a = " << a << " b = " << b << endl;
	myswap3(&a, &b);
	cout << "after  : a = " << a << " b = " << b << endl;
	cout << endl;

	int c  = 0;
	int &d = c;
	int e  = 0;
	int f  = 0;
	int g  = 0;
	cout << "&c - &d = " << &c - &d << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "&c = " << &c << endl;
	cout << "&d = " << &d << endl;
	cout << "&c - &d = " << &c - &d << endl;
	cout << "&e = " << &e << endl;
	cout << "&d - &e = " << &d - &e << endl;
	cout << "&f = " << &f << endl;
	cout << "&e - &f = " << &e - &f << endl;
	cout << "&g = " << &g << endl;
	cout << "&f - &g = " << &f - &g << endl;

	return 0;
}
