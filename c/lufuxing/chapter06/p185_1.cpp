#include<iostream>
using namespace std;
unsigned myCnt()
{
  static unsigned iCnt=-1;
  ++iCnt;
  return iCnt;
}

int main()
{
 cout<<"请输入任意字符后按回车键继续"<<endl;
 char ch;
 while(cin>>ch)
 {
   cout<<"函数myCnt()的执行次数是："<<myCnt()<<endl;
 }
 return 0;
}
