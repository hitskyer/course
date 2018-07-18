#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10,42);
  vector<int> v4{10};
  vector<int> v5{10,42};
  vector<string> v6{10};
  vector<string> v7{10,"hi"};
  
  cout<<"v1的元素个数是："<<v1.size()<<endl;
  if(v1.size() >0)
  {
   cout<<"v1的元素分别是："<<endl;
   for(auto e:v1)
     cout<<e<<" ";
   cout<<endl;
  }

  cout<<"v2的元素个数是："<<v2.size()<<endl;
  if(v2.size() >0)
  {
   cout<<"v2的元素分别是："<<endl;
   for(auto e:v2)
     cout<<e<<" ";
   cout<<endl;
  }

  cout<<"v3的元素个数是："<<v3.size()<<endl;
  if(v3.size() >0)
  {
   cout<<"v3的元素分别是："<<endl;
   for(auto e:v3)
     cout<<e<<" ";
   cout<<endl;
  }
  
  cout<<"v4的元素个数是："<<v4.size()<<endl;
  if(v4.size() >0)
  {
   cout<<"v4的元素分别是："<<endl;
   for(auto e:v4)
     cout<<e<<" ";
   cout<<endl;
  }

  cout<<"v5的元素个数是："<<v5.size()<<endl;
  if(v5.size() >0)
  {
   cout<<"v5的元素分别是："<<endl;
   for(auto e:v1)
     cout<<e<<" ";
   cout<<endl;
  }

  cout<<"v6的元素个数是："<<v6.size()<<endl;
  if(v6.size() >0)
  {
   cout<<"v6的元素分别是："<<endl;
   for(auto e:v6)
     cout<<e<<" ";
   cout<<endl;
  }

  cout<<"v7的元素个数是："<<v7.size()<<endl;
  if(v7.size() >0)
  {
   cout<<"v7的元素分别是："<<endl;
   for(auto e:v7)
     cout<<e<<" ";
   cout<<endl;
  }
  
  return 0;
}
