#include<iostream>
using namespace std;

wchar_t out_var;
int main()
{
	cout << "The memory size of wchar_t  is " << sizeof(wchar_t) << " bytes" << endl;
	wchar_t in_var;
	cout << "in_var= " << in_var << endl;
	cout << "in_var= " << in_var << " (2nd times)" << endl;

	cout << "out_var= " << out_var << endl;
	cout << "out_var= " << out_var << " (2nd times)" <<  endl;
}
