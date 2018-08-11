#include<iostream>
using namespace std;

int main(int argc,char **argv)
{
  string str;
  for(int i=0;i!=argc;++i)
     str+=argv[i];
  cout<<str<<endl;
  return 0;
}
