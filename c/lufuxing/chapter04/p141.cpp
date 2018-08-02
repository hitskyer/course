#include<iostream>
using namespace std;
int main()
{
  int x=10,y=20;
  bool someValue=true;
  someValue ?++x,++y:--x,--y;
  cout<<x<<endl;
  cout<<y<<endl;
  cout<<someValue<<endl;
  x=10,y=20;
  someValue=false;
  someValue? ++x,++y:--x,--y;
  cout<<x<<endl; 
  cout<<y<<endl;
  cout<<someValue<<endl;
  return 0;
}
