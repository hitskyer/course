#include <iostream>
using namespace std;
/* 求两个数据的减法差值*/

int main()

{
  int x, y; string s;
do
  {
      cout << "Please enter two numbers" << endl;
      cout << "-------------------------" << endl;
	
	while (!(cin >> x && cin >> y))
       {
         cout  << "输入值必须是整数，请重新输入：" << endl;
	cin.clear();
	cin.sync();
	cin.get();
       }

      cout << "The sub of " << x << " and " << y << " is " << x-y << endl;
      cout << "If continue to calculate, please enter y or Y; Enter others to quit" << endl;
      cin >> s;
}while(s=="y"||s=="Y");

      return 0;
}


