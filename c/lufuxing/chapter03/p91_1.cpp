#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  vector<string> vString;
  string s;
  char cont='y';
  while(cin>>s)
  {
   vString.push_back(s);
   cout<<"您要继续吗（y or n）？"<<endl;
   cin >>cout;
   if(cont !='y' &&cont !='Y')
    break;
  }
  for(auto mem : vString)
    cout<<mem<<"";
  cout <<endl;
  return 0;
}

