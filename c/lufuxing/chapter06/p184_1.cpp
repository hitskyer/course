#include<iostream>
#include<cmath>
using namespace std;
double myABS(double val)
{
 if(val<0)
    return val * -1;
 else
    return val;
}
double myABS2(double val)
{
  return abs(val);
}
int main()
{
  double num;
  cout<<"请输入一个属：";
  cin>>num;
  cout<<num<<"的绝对值是："<<myABS(num)<<endl;
  cout<<num<<"的绝对值是："<<myABS2(num)<<endl;
  return 0;
}
