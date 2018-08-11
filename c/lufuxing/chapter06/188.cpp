#include<iostream>
using namespace std;
void mySWAP(int *p,int *q)
{
  int tmp=*p;
  *p=*q;
  *q=tmp;
}

int main()
{
  int a=5,b=10;
  int *r=&a,*s=&b;
  cout<<"交换前:a="<<a<<",b="<<b<<endl;
  mySWAP(r,s);
  cout<<"交换后：a="<<a<<",b="<<b<<endl;
  return 0;
}
