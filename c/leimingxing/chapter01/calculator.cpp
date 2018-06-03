#include<iostream>

using namespace std;


int main(){

   int serialNumber;
   int a; int b;
   cout << "1 加法运算 " << endl;
   cout << "请输入'1' 进行运算"  << endl;
   cin >> serialNumber ;

   loop1: if(cin.fail()){
      cin.clear();
      cin.ignore();
      cout << "输入错误,请重新输入" << endl;
      cin >> serialNumber;
      goto loop1;
   }else if(serialNumber==1){
      cout << "请输入两个数字" << endl;
      cin >> a >> b;
     loop2: if(cin.fail()){
       cin.clear();
       cin.ignore();
       cout << "输入错误,请重新输入" << endl;
       cin >> a >> b ;
       goto loop2;
      }else{

       cout << a <<"与" << b <<"的和为" << a+b;
      }
   }
  return 0; 
 }
