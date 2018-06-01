#include <iostream>
int main()
{
	int sum = 0;
	for(int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << "from 50 to 100 sum is " << sum << std::endl;
	return 0;
}
