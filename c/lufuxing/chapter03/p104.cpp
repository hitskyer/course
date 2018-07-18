#include<iostream>
using namespace std;
int main()
{
  const int sz=10;
  int a[sz];
  for(int i = 0; i< sz;i++)

    a[i]=i;
  for(auto val : a)
    cout << val <<"";
  cout <<endl;
  return 0;
}
