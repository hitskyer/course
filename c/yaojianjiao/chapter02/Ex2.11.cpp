//编写程序，要求用户输入两个数——底数（base）和指数
//（exponent），输出底数的指数次方的结果。 

#include<iostream>

using namespace std;

int main(){

   int base=1;

   int exponent=1;

   int result=1;

   cout<<"请输入底数："<<endl;
 
   cin>> base;
  
   cout<< "请输入指数："<<endl;
  
   cin>> exponent;
   
   for(int cnt=0; cnt<exponent; cnt++){
     result *= base;
   }
   cout << base <<"的"<<exponent<<"次方是："<< result<<endl;
 
   return 0; 




}


