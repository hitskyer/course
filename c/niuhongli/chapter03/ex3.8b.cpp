#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
	string InputString, NewString;
	cout << "Enter string: " << endl;
	while (cin >> InputString)
		NewString=NewString+InputString+ ' ';
	cout << endl <<  "New string obtained is: " << NewString <<  endl;
	return 0;
}
	
