#include <iostream>
using namespace std;

int main()
{
//1)  const 变量如果多次使用，可以提前设定
	 const int  upper=100;
	int sum=0, multi=1;
	for (int i=0; i<=upper; ++i){
		 sum+=i;
	}
	for (int j=1; j<=upper/20; ++j){
		multi=multi*j;
	}
	cout << "Sum from 0 to " << upper << " is " << sum << endl;
	cout << "Multiply 1 to " << upper/20  << " is " << multi << endl;
// 2) const 变量不能重新赋值,所以以下程序报错
//	int uppernew=200;
//	upper=uppernew;
//	cout << "upper= " << upper << endl;

// 3) extern const 外部声明，在文件const_EX.cpp 中使用
	extern const string example="Cheer up!";
	return 0;
}

