#include <iostream>

using namespace std;

double &Add(const double &a,const double &b)
{
	return a+b;
}


int main()
{
	double a = 10,b = 12;
	cout << Add(a,b) << endl;
	return 0;
}
