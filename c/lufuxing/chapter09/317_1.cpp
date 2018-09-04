#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
  forward_list<int> ilst={0,1,2,3,4,5,6,7,8,9};
  auto prev =iflst.before_begin();
  auto curr =iflst.begin();

  while(curr != iflst.end()){
     if(*curr & 1){
        curr=iflst.insert_after(curr,*curr);
        prev=curr;
        curr++;
     }else
     curr=iflst.erase_after(prev);
   }

  for(curr=iflst.begin();curr!=iflst.end();curr++)
    cout<<*curr<<" ";
  cout<<endl;

  return 0;
}
