#include<iostream>

int main()
{
 int i=0,&r=i;
 auto a=r;
 const int ci=i, &cr=ci;
 auto b=ci;
 auto c=cr;
 auto d=&i;
 auto e=&ci;
 auto &g=ci;
 std::cout<<a<<" "<< b <<" "<<c<<" "<<d<<" "<< e <<" "<<g<<std::endl;
 a=42;
 b=42;
 c=42;
 d=42;
 e=42;
 g=42;
 std::cout<<a<<" " <<b<<" "<<c<<" " << d <<" " <<e <<" "<<g<<std::endl;
 return 0;
}
