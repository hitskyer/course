#include<iostream>
using namespace std;
double myADD(double val1,double val2)
{
  double result=val1+val2;
  static unsigned iCnt=0;
  ++iCnt;
  cout<<"该函数已经累积执行了"<<iCnt<<"次"<<endl;
  return result;
}

int main()
{
  double num1,num2;
  cout<<"请输入两个数：";
  while(cin>>num1>>num2)
  {
   cout<<num1<<"与"<<num2<<"的求和结果是："
       <<myADD(num1,num2)<<endl;
  }
  return 0;
}
