#include<iostream>
using namespace std;
#include<iomanip>
#include<math.h>

int main()
{
	cout << setiosflags(ios::fixed) << setprecision(1);//需要头文件#include <iomanip>
	double t,d,h,num1,num2;
	char alpha,beta;
	while(cin >> alpha && alpha != 'E')
	{
		cin >> num1 >> beta >> num2;
		if(alpha=='T'&&beta=='D' || alpha=='D'&&beta=='T')
		{
			t = num1;
			d = num2;
			if(alpha=='D')
				swap(t,d);
			h=t+0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10);
		}
		else if(alpha=='T'&&beta=='H' || alpha=='H'&&beta=='T')
		{
			t = num1;
			h = num2;
			if(alpha=='H')
				swap(t,h);
			d=1/(1/273.16-log(((h-t)/0.5555+10.0)/6.11)/5417.7530)-273.16;;
		}
		else if(alpha=='D'&&beta=='H' || alpha=='H'&&beta=='D')
		{
			d = num1;
			h = num2;
			if(alpha=='H')
				swap(d,h);
			t=h-0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
		}	
		cout << "T " << t << " D " << d << " H " << h << endl; 
	}
	return 0;
}