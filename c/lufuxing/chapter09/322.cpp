#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
  vector<char> vc={'H','e','l','l','o'};
  string s(vc.data(),vc.size());
  cout<<s<<endl;

return 0;
}
