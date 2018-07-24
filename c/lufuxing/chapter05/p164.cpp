#include<iostream>
using namespace std;

int main()
{
  unsigned int vowelCnt=0;
  char ch;
  cout<<"请输入一段文本："<<endl;
  while(cin>>ch)
  {
   if(ch=='a')
     ++vowelCnt;
   if(ch=='e')
     ++vowelCnt;
   if(ch=='i')
     ++vowelCnt;
   if(ch=='o')
     ++vowelCnt;
   if(ch=='u')
     ++vowelCnt;
  }
  cout<<"您输入的文本中有"<<vowelCnt<<"个元音字母"<<endl;
  return 0;
}
