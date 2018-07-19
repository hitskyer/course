#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
  const int sz=10;
  int a[sz];
  srand((unsigned)time(NULL));
  cout<<"数组的内容是："<<endl;
  for(auto &val : a)
  {
   val =rand()%100;
   cout<<val<<" ";
  }
  cout <<endl;

  vector<int> vInt(begin(a),end(a));
  cout<<"vector的内容是："<<endl;
  for (auto val :vInt)
  {
   cout<<val<<" ";
  }
  cout<<endl;
  return 0;
}
