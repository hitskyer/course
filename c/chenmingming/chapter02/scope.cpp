#include<iostream>
int main()
{
	int x=9;
	std::cout << x << std::endl;
	while(1)
	{
		x=1;
		std::cout << x << std::endl;
		break;
	}
	x=8;
	std::cout << x << std::endl;
	for(;;)
	{
		int x=2;
		std::cout << x << std::endl;
		break;
	}
	std::cout << x << std::endl;
}
