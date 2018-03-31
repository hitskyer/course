#include <iostream>
using namespace std;
char out_char;
int main()
{
	cout << "size of char is " << sizeof(char) << " bytes" << endl;
	char a;
	cout << "uninitialized_inside_char " << a << endl;
	cout << "uninitialized_inside_char " << a << endl;

	cout << "uninitialized_outside_char " << out_char << endl;
	cout << "uninitialized_outside_char " << out_char << endl;
	char c='\t', d='\n', e='\a';
	cout << "c is " << c << endl
		<< "d is " << d << endl
		<< "e is " << e << endl;
	return 0;
}
