#include <iostream>
using namespace std;
/* 求两个数据的减法差值*/

int main()

{
  int x, y; string s;
do
  {
      cout << "Please enter two integers (请输入两个整数)" << endl;
      cout << "-------------------------" << endl;
      cin >> x >> y; // 输入x和y整数I
      cout << "The sub of " << x << " and " << y << " is " << x-y << endl;
      
      cout << "If continue to calculate, please enter y or Y; Enter others to quit" << endl;
      cin >> s;
}while(s=="y"||s=="Y");

      return 0;
}


