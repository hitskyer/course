#include<iostream>
int main()
{
  int sum = 0, value = 0;
  std::cout<<"请输入一些数，按Ctrl+z表示结束"<<std::endl; 
  for (; std::cin >> value;)
   sum +=value;
  std::cout<<"这些数的和为"<<sum<<std::endl;
  return 0;
}
