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
 if(vInt.cbegin() == vInt.cend())
 {
  cout<<"没有任何元素"<<endl;
  return -1;
 }
 cout <<"相邻两项的和依次是:"<<endl;
 for(auto it =vInt.cbegin() ;it!= vInt.cend()-1;it++)
 {
   cout<<(*it +*(++it))<<" ";
   if((it-vInt.cbegin()+1)%10 == 0)
    cout<<endl;
 }
 if(vInt.size() % 2!=0)
  cout << *(vInt.cend() -1);
 return 0;
}

