#include <string>
#include <iostream>
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;

int main ()
{
	string juwenhui;
//	while (cin >> juwenhui)
//		cout << juwenhui << endl;

	while (getline(cin,juwenhui))
		cout << juwenhui << endl;
	return 0;
}
