#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string word;
// 读入单词； 遇到空格终止并返回	
	while (cin >> word)	
		cout << word << endl;
	return 0;
}

