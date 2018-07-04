#include<iostream>
using namespace std;

int abs(int x)
{	
	return x>=0? x: -x;
}

int main()
{
	int xval;
	cin >> xval;
	cout << "The absolute value of " << xval << " is " << abs(xval) << endl;
	return 0;
}
