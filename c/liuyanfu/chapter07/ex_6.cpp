#include <iostream>
using namespace std;

int& maxmium(int &a,int &b)
{
	return a>b?a:b;
}


int main()
{
	cout << "Enter two numbers of int type:" << endl;
	int a = 0;
	int b = 0;
	cin >> a >> b;
	int result = maxmium(a,b);
	cout << "The maxmium between the " << a << " and " << b << " is " << result << endl;
	return 0;
}
