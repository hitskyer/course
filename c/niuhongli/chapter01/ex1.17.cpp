#include <iostream>
//编写程序，要求用户输入一组数。输出信息说明其中有多少个负数

int main()
{
std::cout << "Enter a string of numbers:" << std::endl;
int v, count=0;
while (std::cin >> v)
{
if (v<0)
++ count;
}
std::cout << "There are " << count << " negative numbers" << std::endl;
return 0;
}
