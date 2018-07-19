#include<iostream>
using namespace std;

int main()
{
  const int sz=10;
  int a[sz],i=0;
  for(i=0;i<10;i++)
    a[i]=i;
  cout<<"初始状态下数组的内容是："<<endl;
  for(auto val :a)
    cout<<val<< " ";
  cout<<endl;
  int *p =begin(a);
  while (p !=end(a))
  {
  *p =0;
  p++;
  }
 cout<<"修改后的数组内容是："<<endl;
 for (auto val:a)
    cout << val<< " ";
 cout <<endl;
 return 0;
}
