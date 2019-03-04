#include<iostream>
int main()
{
	int i = 1;
	int a = 0 , b = 0;
	a = 2 + i++;
	i = 1;
	b = 2 + ++i;
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;
	return 0;
}
