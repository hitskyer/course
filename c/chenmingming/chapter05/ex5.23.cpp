#include<iostream>
int main()
{
	int x[10];
	int *p = x;
	std::cout << sizeof(int)<<std::endl;
	std::cout << sizeof(p)<<std::endl;
	std::cout << sizeof(x)/sizeof(*x)<<std::endl;
	std::cout << sizeof(p)/sizeof(*p)<<std::endl;

}
