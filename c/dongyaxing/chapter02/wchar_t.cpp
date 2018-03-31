#include <iostream>

using namespace std;

	wchar_t gc;
	int main()
	{
		wchar_t c;
		cout << "wchar类型的全局变量的默认值： " << gc << endl;
		cout << "wchar类型的局部变量的默认值： " << c << endl;
		cout << "wchar类型变量的存储长度： "<< sizeof(c) << endl;
		return 0;
	}
