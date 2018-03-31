#include<iostream>

int main()
{
int base, exponent;
long result=1;

std::cout << "Enter base and exponent:"<< std::endl;

std::cin >> base >> exponent;

if (exponent < 0) {
	std::cout << "Exponent can't be negative" << std::endl;
	return -1;
	}
if (exponent > 0) {
	for (int i=1; i<=exponent; ++ i)
	result=result*base;
	std::cout << base << " raised to the power of " << exponent 
	<< ": " << result << std::endl;
	return 0;
	}
}

