#include<iostream>
using namespace std;


int main() {

  //定义变量a
  int a = 10;

  do{
 
  cout << "a的值为" << a << endl;

  a=a+1;

  if(a>15){
   
    break; 

  }

  }while(a<20);


  return 0;

}
