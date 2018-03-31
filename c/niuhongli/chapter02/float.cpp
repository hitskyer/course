#include<iostream>
using namespace std;

float out_var;
int main()
{
	cout << "The memory size of float is " << sizeof(float) << " bytes" << endl;
	float in_var;
	cout << "in_var= " << in_var << endl;
	cout << "in_var= " << in_var << " (2nd times)" << endl;

	cout << "out_var= " << out_var << endl;
	cout << "out_var= " << out_var << " (2nd times)" <<  endl;
}
