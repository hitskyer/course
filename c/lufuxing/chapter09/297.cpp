#include<iostream>
#include<vector>
using namespace std;

bool search_vec(vector<int>::iterator beg,
        vector<int>::iterator end,int val)
{ 
   for(;beg != end; beg++)
       if(*beg==val)
         return true;
       return false;
}

int main()
{
  vector<int>ilist={1,2,3,4,5,6,7};
  
  cout<<search_vec(ilist.begin(),ilist.end(),3)<<endl;
  cout<<search_vec(ilist.begin(),ilist.end(),8)<<endl;

  return 0;
}
