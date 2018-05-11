#include <iostream>
using namespace std;

int main()
{
	enum day{Sunday,Monday,Tuesday,Wensday,Thursday,Friday,Saturday};
	cout<<Sunday<<Monday<<Tuesday<<Wensday<<Thursday<<Friday<<Saturday<<endl;
	enum num {a=2,b,c=3,d};
	cout<<a<<b<<c<<endl;
	enum color{red,blue=3,green,yellow=4};
	cout<<red<<blue<<green<<yellow<<endl;
	return 0;
}
