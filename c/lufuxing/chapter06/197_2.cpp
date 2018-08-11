#include<iostream>
using namespace std;

int iCount(initializer_list<int> il)
{
  int count = 0;
  for (auto val:il)
     count+=val;
  return count;
}

int main()
{
  cout<<"1,6,9的和是："<<iCount({1,6,9})<<endl;
  cout<<"4,5,9,18的和是："<<iCount({4,5,9,18})<<endl;
  cout<<"10,10,10,10,10,10,10,10,10的和是："
      <<iCount({10,10,10,10,10,10,10,10,10})<<endl;
  return 0;
}
