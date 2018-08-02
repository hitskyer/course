#include<iostream>
using namespace std;
void SwapPointer1(int *p,int *q)
{
  int *temp=p;
  p=q;
  q=temp;
}

void SwapPointer2(int *p,int *q)
{
  int temp=*p;
  *p=*q;
  *q=temp;
}

void SwapPointer3(int *&p,int *&q)
{
  int *temp=p;
  p=q;
  q=temp;
}

int main()
{
  int a=5,b=10;
  int *p=&a,*q=&b;
  cout<<"交换前："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是：0"<<*p<<",q所指的值是："<<*q<<endl;
  SwapPointer1(p,q);
  cout<<"交换后："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;

  a=5,b=10;
  p=&a,q=&b;
  cout<<"交换前："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是：0"<<*p<<",q所指的值是："<<*q<<endl;
  SwapPointer2(p,q);
  cout<<"交换后："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;

  a=5,b=10;
  p=&a,q=&b;
  cout<<"交换前："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是：0"<<*p<<",q所指的值是："<<*q<<endl;
  SwapPointer3(p,q);
  cout<<"交换后："<<endl;
  cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
  cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
  return 0;
}
