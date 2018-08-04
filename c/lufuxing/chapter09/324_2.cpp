#include<iostream>
#include<vector>
#include<string>

using namespace std;

void name_string(string &name, const string &prefix,const string &suffix)
{
  name.insert(name.begin(),1,' ');
  name.insert(name.begin(),prefix.begin(),prefix.end());
  name.append(" ");
  name.append(suffix.begin(),suffix.end());
}

int main()
{
  string s="Jame Bond";
  name_string(s,"Mr.","Ⅱ");
  cout<<s<<endl;

  s="M";
  name_string(s,"Mrs.","ⅡⅡ");
  cout<<s<<endl;
 
return 0;
}
