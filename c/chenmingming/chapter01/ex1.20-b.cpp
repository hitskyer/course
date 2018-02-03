#include <iostream>
#include <stdio.h>
int main()
{
	std::cout << "input two numbers, it will tell you sum of numbers between them "<< std::endl;
	int x, y, sum=0, x1;
	std::cin >> x >> y;
	x1=x;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n输出结果为：\n");
	while(x<=y)
	{
	sum += x;
	x++;
	}
	std::cout << "the sum of numbers between " << x1 << " and " << y << " is " << sum;
	std::cout << std::endl;
	return 0;
}
