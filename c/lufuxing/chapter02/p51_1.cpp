#include <iostream>
#include <cstdlib>
int main()
{
 int i=0;
 int *p1 = nullptr;
 int *p=&i;
 if (p1)
   std::cout<<"p1 pass"<<std::endl;
 if (p)
   std::cout<<"p pass"<<std::endl;
 if (*p)   
   std::cout<<"i pass"<<std::endl;
 return 0;
}
