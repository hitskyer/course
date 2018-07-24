#include<iostream>
using namespace std;
int main()
{
  cout<<"请依次输入被除数和除数："<<endl;
  int ival1,ival2;
  cin>>ival1>>ival2;
  if(ival2==0)
  {
    cout<<"除数不能为0"<<endl;
    return -1;
  }
  cout<<"两数相除的结果是："<<ival1/ival2<<endl;
  return 0;
  
}
