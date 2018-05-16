#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int base, exponent;
	long result=1;
	cout << "Please 输入分别输入底数和指数: " << endl;
	cin >> base >> exponent;
	if (exponent <0 ){
		cout << "Exponent can not be negative" << endl;	
	return -1;
	}
	if (exponent >0){
		for (int i=1;i<=exponent;++i)
		 result*=base;
	}
	cout << base << " raised to the power of " << exponent  << " is " 
	<< result << endl;	
	return 0;
}
