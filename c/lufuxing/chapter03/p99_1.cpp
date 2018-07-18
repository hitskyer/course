#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  vector<string> text;
  string s;
  while(getline(cin,s))
           text.push_back(s);
  for(auto it =text.begin();it !=text.end() && !it ->empty();it++)
  {
   for(auto it2=it ->begin();it2 !=it -> end(); it2++)
     *it2=toupper(*it2);
   cout<<*it<<endl;
  }

  return 0;
}
