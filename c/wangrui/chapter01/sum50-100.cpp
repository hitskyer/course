#include<iostream>

using namespace std;

int main()
{  

  int sum = 0,val=50;
  //for (int i=50;i<=100;++i)
  // sum +=i;
  
  //cout<<"50-100之间所有自然数之和是：  "<< sum <<endl;
  while(val<=100){

    sum  += val;    
   
    ++val;

  }
  cout<<"50-100之间所有自然数之和是：  "<< sum <<endl;  
  return 0;


}
