#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
  forward_list<int> iflst={1,2,3,4,5,6,7,8};

  auto prev=iflst.before_begin();
  auto curr=iflst.begin();
 
  while (curr !=iflst.end())
    if(*curr & 1)
      curr=iflst.erase_after(prev);
    else{
     prev=curr;
     curr++;
   }
   for(curr=iflst.begin();curr!=iflst.end();curr++)
    cout<<*curr<<" ";
   cout<<endl;
 
   return 0;
}
