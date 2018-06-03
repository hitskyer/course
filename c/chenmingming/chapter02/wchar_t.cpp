#include <iostream>
#include<cmath>
using namespace std;
wchar_t out_wchar_t;
int main()
{
	cout << "size of wchar_t is " << sizeof(wchar_t) << " bytes" << endl;
	wchar_t a;
	cout << "uninitialized_inside_wchar_t " << a << endl;
	cout << "uninitialized_inside_wchar_t " << a << endl;

	cout << "uninitialized_outside_wchar_t " << out_wchar_t << endl;
	cout << "uninitialized_outside_wchar_t " << out_wchar_t << endl;

	return 0;
}
