#include<iostream>

using namespace std;

int main(){


   int value = 2;
   int pow = 10;
   int result = 1;
  
   for(int cnt = 0; cnt < pow; cnt++)
     
     result  *= value;

  cout << value 
 << " raised to the power of " 
 << pow << ": \t" 
 << result << std::endl; 
  
 return 0;

}
