#include<iostream>
#include<list>

using namespace std;

int main()
{
  list<string> sl;
  
  string word;
  while(cin>>word)
    sl.push_back(word);
 
  for(auto si=sl.cbegin();si !=sl.cend();si++)
    cout<<*si<<endl;

  return 0;
}
