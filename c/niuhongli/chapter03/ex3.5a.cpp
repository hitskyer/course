#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	// 读入一行文本，遇到换行符终止并返回；
		cout << line << endl;
	return 0;
}

