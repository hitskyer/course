#include <iostream>
using namespace std;
/* 求两个数据乘积*/

int main()

{
  float x, y; string s;
do
  {
      cout << "Please enter two numbers" << endl;
      cout << "-------------------------" << endl; 
      while(!(cin >> x >>y))
            {
                      cout << "Warning: numbers should be entered!\n Please enter again: \n";
                      cin.clear();
                      cin.ignore(1000,'\n');
            }
      cout  << x << " multiplied by " << y << " is " << x*y << endl;
      cout << "-------------------------" << endl;
      cout << "If continue, please enter y or Y; if not, enter other letters or numbers to quit~"
            << endl;
      cin >> s;
}while(s=="y"||s=="Y");

      return 0;
}


