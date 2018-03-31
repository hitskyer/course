#include <iostream>
int main()
{
	int base = 1, exponent = 0, n=1, val=1;
	std::cout << "please enter base and exponent!" << std::endl;
	std::cin >> base >> exponent;
	for(;n<=exponent;++n)
	{
		val *= base;
	}
	std::cout << "val is " << val << std::endl;
	return 0;
}
