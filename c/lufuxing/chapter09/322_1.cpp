#include<iostream>
#include<vector>
#include<string>

using namespace std;

void input_string(string &s)
{
  s.reserve(100);
  char c;
  while (cin>>c)
       s.push_back(c);
}
int main()
{
  string s;
  input_string(s);
  cout<<s<<endl;

return 0;
}
