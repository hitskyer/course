#include<iostream>
#include<string>
using namespace std;
int main()
{
  string finalgrade;
  int grade;
  cout<<"请输入您要检查的成绩："<<endl;
  while(cin>>grade&&grade>=0 && grade<=100)
  {
   finalgrade=(grade>90)?"high pass"
                       :(grade>75)?"pass"
                       :(grade>60)?"low pass":"fail";
   cout<<"该成绩所处的档次是："<<finalgrade<<endl;
   cout<<"请输入您要检查的成绩："<<endl;
  }
  return 0;
}
