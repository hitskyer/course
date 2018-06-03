#include<iostream>
using namespace std;

long double out_var;
int main()
{
	cout << "The memory size of long double is " << sizeof(long double) << " bytes" << endl;
        long double in_var;
	cout << "in_var= " << in_var << endl;
	cout << "in_var= " << in_var << " (2nd times)" << endl;

	cout << "out_var= " << out_var << endl;
	cout << "out_var= " << out_var << " (2nd times)" <<  endl;
}
