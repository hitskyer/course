#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> iv={1,1,2,1};
  int some_val =1;

  vector<int>::iterator iter=iv.begin();
  int org_size=iv.size(),new_ele=0;
  
  while(iter != (iv.begin()+org_size/2+new_ele))
    if(*iter ==some_val){
      iter=iv.insert(iter,2*some_val);
      new_ele++;
      iter++;iter++;
   }  else iter++;
 
  for(iter=iv.begin();iter!=iv.end();iter++)
    cout<<*iter<<endl;
  
  return 0;
}

