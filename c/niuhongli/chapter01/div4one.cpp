#include <iostream>
using namespace std;
/* 求两个整数的除法*/

int main()

{
  float  x, y; string s;
do
  {
      cout << "Please enter two numbers" << endl;
      while (true)
      {
          if (!(bool(cin >> x >> y)))
     	    {
      		 cout << "Warning: numbers should be entered, please enter again:\n" << endl;
  		 cin.clear();
                 cin.ignore(1000,'\n'); 
 		 continue;
      	    }
     		 else if (bool(y==0))
			{
                         cout << "Divisor can not be 0, please enter agan: \n" << endl;
 			 cin.clear();
			 cin.ignore(1000,'\n');
			 continue;
			 }
		 else 
			{
                         cout  << x << " divided by " << y << " is " << x/y << endl;
			 break;
			}
	}
        cout << "If continue, please enter y or Y; if not, enter other letters or numbers to quit~"
             << endl;
        cin >> s;
}while(s=="y"||s=="Y");

      return 0;
}


