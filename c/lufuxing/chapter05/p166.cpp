#include<iostream>
#include<string>
using namespace std;

int main()
{
  string currString,preString="",maxString;
  int currCnt =1,maxCnt=0;
  while(cin>>currString)
  {
    if(currString==preString)
    {
      ++currCnt;
      if(currCnt>maxCnt)
      {
        maxCnt=currCnt;
        maxString=currString;
      }
    }
    else
    {
      currCnt=1;
    }
    preString=currString;
  }
  if(maxCnt>1)
    cout<<"出现最多的字符串是："<<maxString<<"，次数是："<<maxCnt<<endl;
  else
    cout<<"每个字符串都只出现了一次"<<endl;
  return 0;
}
