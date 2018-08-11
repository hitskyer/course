#include<iostream>
using namespace std;
//string stringcopy(string word)
string stringcopy(string &word)
{
	word = word + ' ' + word;
	static int a = 0;
	if(a<5)
	{
		++a;
		stringcopy(word);
	}
}
int main()
{
	size_t n = 100;
	string longword(n, 'a');
	//cout << longword << endl;
	string temp = stringcopy(longword);
	//cout << stringcopy(longword) << endl;
	return 0;
}
