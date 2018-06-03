#include<iostream>

#include<cstring>

using namespace std;



int main()

{

	const size_t str_size=50;

	char str1[str_size];

	char str2[str_size]; 

	cout << "输入两个字符串: " << endl;

	cin >> str1 >> str2;

	if (strcmp(str1,str2)>0)

		cout << "str1 > str2" << endl;

	else if (strcmp(str1,str2)<0)

		cout << "str1 < str2" << endl;

	else

		cout << "str1=str2" << endl;

}
