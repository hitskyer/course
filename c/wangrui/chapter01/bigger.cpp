#include<iostream>

using namespace std;

//编写程序，输出用户输入的两个数中的较大者。
int main()
{
cout<<"请输入两个数："<<endl;
int v1=0,v2=0;
cin>>v1>>v2;
if (v1>=v2){

  cout<<"两个数中较大的数字是："<<v1<<endl;

}else{

  cout<<"两个数中较大的数字是："<<v2<<endl;

}

return 0;

}
