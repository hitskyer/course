#include <iostream>
using namespace std;

wchar_t out_main;
int main() {
	cout << "the size of wchar_t is " << sizeof(wchar_t) << " bytes" << endl;
	
	wchar_t in_main;
	cout << "int(out_main) = " << int(out_main) << "(0, every time)"<< endl;
	cout << "int(in_main) = " << int(in_main) << "(not sure?)" << endl;

	return 0;
}
