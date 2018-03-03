#include <iostream>

#include <string>

int main()

{

	using namespace std;

	double x=0,y=0;

	char s;

	do

	{

		cout << "------------------\n请输入两个数，求乘积！\n";

		while(!(cin >> x >>y))

		{

			cout << "输入了非数字，请输入数字！\n";

			cin.clear();

			cin.ignore(1000,'\n');

		}

		cout << x << " and " << y << "的乘积为：" << x*y << "\n";

		cout << "请输入y或者Y继续计算，输入其他字符结束计算！"<< endl;

		cin.ignore(1000,'\n');

		s=cin.get();

		cin.ignore(1000,'\n');

	}

	while(s == 'y' || s == 'Y');

	return 0;

}
