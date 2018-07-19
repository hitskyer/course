#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
  const int sz=5;
  int a[sz],b[sz],i;
  srand((unsigned) time (NULL) );
  for(i=0;i<sz;i++)
   a[i]=rand()%10;
  cout<<"系统数据已经生成，请输入您猜测的5个数字（0-9），可以重复："<<endl;
  int uVal;
  for(i=0;i<sz;i++)
    if(cin>>uVal)
      b[i]=uVal;
  cout<<"系统生成的数据是："<<endl;
  for(auto val:a)
   cout<<val<<" ";
  cout<<endl;
  cout<<"您猜测的数据是："<<endl;
  for(auto val : b)
   cout<<val<<" ";
  cout <<endl;
  int *p=begin(a),*q=begin(b);
  while(p !=end(a) &&q != end(b))
  {
    if(*p != *q)
     {
        cout<<"您的猜测错误，两个数组不相等"<<endl;
        return -1;
     }
     p++;
     q++;
  }
  cout<<"恭喜您全部猜对了！"<<endl;

  return 0;
}
