#include <iostream>
int main()
{
	std::cout << "enter lots of  numbers:" << std::endl;
	int sum = 0, i = 0;
	while(std::cin >> i )
	{
		if(i < 0)
		{
		++sum;
		}
	}
	std::cout << "the negtive number is totally " << sum ;
	return 0;
}
