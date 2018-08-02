#include<iostream>
using namespace std;
 
int main()
{
 unsigned int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
 unsigned int spaceCnt=0,tabCnt=0,newlineCnt=0;
 char ch;
 cout<<"请输入一段文本："<<endl;
 while(cin.get(ch))
 {
  switch(ch)
  {
   case'a':
   case'A':
     ++aCnt;
     break;
   case'e':
   case'E':
     ++eCnt;
     break;
   case'i':
   case'I':
     ++iCnt;
     break;
   case'o':
   case'O':
     ++iCnt;
     break;
   case'u':
   case'U':
     ++uCnt;
     break;
   case ' ':
     ++spaceCnt;
     break;
   case'\t':
     ++tabCnt;
     break;
   case'\n':
     ++newlineCnt;
     break;
   }
  }
 cout<<"元音字母a的数量是："<<aCnt<<endl;
 cout<<"元音字母e的数量是："<<eCnt<<endl;
 cout<<"元音字母i的数量是："<<iCnt<<endl;
 cout<<"元音字母o的数量是："<<oCnt<<endl;
 cout<<"元音字母u的数量是："<<uCnt<<endl;
 cout<<"空格的数量是是："<<spaceCnt<<endl;
 cout<<"制表符的数量是："<<tabCnt<<endl;
 cout<<"换行符的数量是："<<newlineCnt<<endl;
 return 0;
}
