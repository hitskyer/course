#include <iostream>
#include <stdio.h>
int main()
{
	std::cout << "input two numbers: 1000, 2000 "<< std::endl;
	int x, y, low, up, count=0;
	std::cin >> x >> y;
	if(x <= y)
	{
	low=x;
	up=y;
	}
	else{low=y; up=x;}
	for(;low<=up; ++low)
	{
	std::cout << low << " ";
	++count;
		if(count==10)
		{
		printf("\n");
		count=0;
		}
		else{}
	}
	std::cout << std::endl;
	return 0;
}
