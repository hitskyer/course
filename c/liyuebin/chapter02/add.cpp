#include <iostream>

int add(int &a, int &b)
{
	return a + b;
}

int main()
{
	int a = 10;
	int b = 20;
	std::cout << add(a,b)<< std::endl;
	return 0;
}
