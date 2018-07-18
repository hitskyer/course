#include<iostream>
using namespace std;
string stringcopy(string word)
//string &stringcopy(string &word)
{
	word = word + ' ' + word;
	return word;
}
int main()
{
	size_t n = 929000000;
	string longword(n, 'a');
	//cout << longword << endl;
	string temp = stringcopy(longword);
	//cout << stringcopy(longword) << endl;
	return 0;
}
