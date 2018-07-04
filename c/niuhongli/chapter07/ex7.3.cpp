#include<iostream>
using namespace std;

int power(int x, int y)
{
	int result=1;
	for (int loop =1;loop<=y;++loop)
		result *=x;
	return result;
}

int main()
{
	int xval,yval;
	cout << "Please enter two number: " << endl;
	cin >> xval >> yval;
	if (yval <0){
		cout << "Error, second number should be positive" << endl;
		return -1;
	}
	cout << xval << " raised by " << yval << " is " << power(xval,yval) << endl;
	return 0;
} 
