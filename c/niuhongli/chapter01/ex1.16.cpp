#include <iostream>
//编写程序，输出用户输入数中的两个较大者
 
int main()
{
std::cout << "Enter two numbers:" << std::endl;
int v1, v2;
std::cin >> v1 >> v2;
if (v1<v2)
{
std::cout << "The bigger number is: " << v2 << std::endl;
}
	else if (v1==v2)
	{
	std::cout << "The two number are the same, they are both: " << v1 << std::endl;
	}
	else {
	std::cout << "The bigger number is: " << v1 << std::endl;
	}
return 0;
}

