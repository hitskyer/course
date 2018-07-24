#include<iostream>
using namespace std;
int main()
{
  unsigned int ffCnt=0,flCnt=0,fiCnt=0;
  char ch,prech='\0';
  cout<<"请输入一段文本："<<endl;
  while(cin>>ch)
  {
   bool bl=true;
   if(prech=='f')
   {
     switch(ch)
     {
     case'f':
      ++ffCnt;
      bl=false;
      break;
     case'l':
      ++flCnt;
      break;
     case'i':
      ++fiCnt;
      break;
     }
   }
   if(!bl)
    prech='\0';
   else
    prech=ch;
  }
  cout<<"ff的数量是："<<ffCnt<<endl;
  cout<<"fl的数量是："<<flCnt<<endl;
  cout<<"fi的数量是："<<fiCnt<<endl;
  return 0;
}
