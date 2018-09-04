#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> ivec={1,2,3,4,5,6,7};
  vector<int> ivec1={1,2,3,4,5,6,7};
  vector<int> ivec2={1,2,3,4,5};
  vector<int> ivec3={1,2,3,4,5,6,8};
  vector<int> ivec4={1,2,3,4,5,7,6};
  
  cout<<(ivec==ivec1)<<endl;
  cout<<(ivec==ivec2)<<endl;
  cout<<(ivec==ivec3)<<endl;
  cout<<(ivec==ivec4)<<endl;

  ivec1.push_back(8);
  ivec1.pop_back();
  cout<<ivec1.capacity()<<" "<<ivec1.size()<<endl;
  cout<<(ivec==ivec1)<<endl;
  
  return 0;
}
