#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	string str1;
	cout << "Enter string: " << endl;
	cin >> str1;
	
	const size_t arr_sz=10;
	char pa[arr_sz];
	
	size_t len=strlen(str1.c_str());
	if (len>arr_sz)
	{
		cout << "字符串的长度大于数组长度" <<endl;

	}
	else 
	{
		strncpy(pa,str1.c_str(),len);
	}
	cout << "输出数组元素：" << endl;
	for (size_t ix=0; ix!=arr_sz;++ix)
		cout << pa[ix];
}

