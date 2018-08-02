#include<iostream>
#include<string>
using namespace std;

string make_plural(size_t ctr, const string &word,const string &ending= "s")
{
  return(ctr>1) ? word +ending :word;
}

int main()
{
  cout<<"success的单数形式是："<<make_plural(1,"success","es")
      <<endl;
  cout<<"success的复数形式是："<<make_plural(2,"success","es")
      <<endl;
  cout<<"failure的单数形式是："<<make_plural(1,"failure")<<endl;
  cout<<"failure的单数形式是："<<make_plural(2,"failure")<<endl;
  return 0;
}
