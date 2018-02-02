#include <iostream>
int main()
{
	std::cout << "input two numbers: "<< std::endl;
	int x, y, low, up;
	std::cin >> x >> y;
	if(x <= y)
	{
	low=x;
	up=y;
	}
	else{low=y; up=x;}
	for(;low<=up; ++low)
	{std::cout << low << " ";}
	std::cout << std::endl;
	return 0;
}
