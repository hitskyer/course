#include <iostream>

using namespace std;

int Add(int a, int b)
{
	return a+b;
}

double Add(double a, double b)
{
	return a+b;
}

int Add()
{
	return 10+12;
}
double Add(double a)
{
	return a+15;
}


int main()
{
	double a =10.5,b = 12.3;
	double a1= 12,b1 =3;
	cout << "Add()= 10+12 = " << Add() << endl;
	cout << "Add(a1,b1) = 12 + 3 = " << Add(a1,b1) << endl;
	cout << "Add(a,b) = 10.5 + 12.3 =  " << Add(a,b) << endl;
	cout << "Add(a) = 10.5 + 15 =  " << Add(a) << endl;
	return 0;
}
