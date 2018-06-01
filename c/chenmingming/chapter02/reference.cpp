#include <iostream>
using namespace std;
int main()
{
	int love = 521;
	int &sweet = love;	//只能是对象，不能是数值或者未初始化
	cout << "love = " << love << "sweet = " << sweet;
	sweet = 520;
	cout << "给sweet赋值520后sweet=" << sweet << " love= " << love << endl;

	int &happy=sweet, &smile=happy;
	cout << love << sweet << happy << smile << endl;
	happy=100;
	cout << love << sweet << happy << smile << endl;
	const int good = 99;
	const int &well = good;
}
