#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp= *x;
	*x=*y;
	*y=temp;
}

int main()
{
	int xval,yval;
	cout << "please enter two numbeers: " << endl;
	cin >> xval >> yval;
	cout << "Before swapped: " << "x= " << xval << " y= " << yval << endl;
	swap (&xval, &yval);
	cout << "After swapped: " << "x= "<< xval << " y= " << yval << endl;

	return 0;
} 
