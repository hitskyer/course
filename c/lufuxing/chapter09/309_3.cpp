#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<string> svec;

  string word;
  auto iter=svec.begin();
  while (cin>>word)
    iter=svec.insert(iter,word);

  for(auto iter=svec.cbegin();iter!=svec.cend();iter++)
    cout<<*iter<<endl;

  return 0;
}
