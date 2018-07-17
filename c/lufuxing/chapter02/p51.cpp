#include <iostream>
int main()
{
 int i=5,j=10;
 int *p=&i;
 std::cout<< p << " "<<*p<<std::endl;
 p=&j;
 std::cout<< p << " "<<*p<<std::endl;
 *p=20;
 std::cout<< p << " "<<*p<<std::endl;
 j=30;
 std::cout<< p << " "<<*p<<std::endl;
 return 0;
}
