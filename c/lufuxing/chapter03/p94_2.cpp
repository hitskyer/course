#include<iostream>
#include<vector>
using namespace std;
int main()
{
 vector<int> vInt;
 int iVal;
 cout<<"请输入一组数字:"<<endl;
 while(cin>>iVal)
    vInt.push_back(iVal);
 if(vInt.size() == 0)
 {
  cout<<"没有任何元素"<<endl;
  return -1;
 }
 cout <<"相邻两项的和依次是:"<<endl;
 for(decltype(vInt.size()) i=0; i<vInt.size()-1;i+=2)
 {
   cout<<vInt[i]+vInt[i+1]<<" ";
   if((i+2) % 10==0)
    cout<<endl;
 }
 if(vInt.size() % 2!=0)
  cout <<vInt[vInt.size() -1];
 return 0;
}
