#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
  list<char *> slist={"hello","world","!"};
  vector<string> svec;
  
  svec=slist;
  svec.assign(slist.begin(),slist.end());
 
  cout<<svec.capacity()<<" "<<svec.size()<<" "
      <<svec[0]<<" "<<svec[svec.size()-1]<<endl;
  
  return 0;
}
