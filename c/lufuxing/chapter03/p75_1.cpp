#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
 cout<<"请输入两个数";
 cout<<endl;
 int v1=0,v2=0;
 cin>>v1>>v2;
 if(v1>v2)
   while (v1>=v2){
     cout<<v1<<" ";
     v1--;
   }
 else
   while (v1<-v2){
     cout<<v1<<" ";
     v1++;
   }
cout<<endl;
return 0;
}

