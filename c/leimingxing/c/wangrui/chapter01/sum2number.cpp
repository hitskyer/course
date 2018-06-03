#include<iostream>

using namespace std;

int main()
{

  cout<<"Enter two numbers:"<<endl;
  
  int v1=0,v2=0,lower=0,upper=0;
  
  cin>>v1>>v2;
   
  if(v1<=v2){

     lower=v1;
     upper=v2;

  }else{

     upper=v1;
     lower=v2;

   }
  int sum=0;
  for(int val=lower;val<=upper;++val)
    sum  +=val;
  
  cout<<"The sum of "<<lower<<" and  "<<upper<<" is  "<<sum<<endl;
  return 0;
    

  


}
