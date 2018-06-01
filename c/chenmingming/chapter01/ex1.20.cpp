#include <iostream>
#include <stdio.h>
int main()
{
	std::cout << "input two numbers, it will tell you sum of numbers between them "<< std::endl;
	int x, y, low, up, sum=0;
	std::cin >> x >> y;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n输出结果为：\n");
	if(x <= y)
	{
	low=x;
	up=y;
	}
	else{low=y; up=x;}
	for(;low<=up; ++low)
	sum += low;
	std::cout << "the sum of numbers between " << x << " and " << y << " is " << sum;
	std::cout << std::endl;
	return 0;
}
