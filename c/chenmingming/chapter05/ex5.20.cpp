#include<iostream>
using namespace std;
int main()
{
	int x1,x2;
	cout << "enter 2 numbers!" << endl;
	cin >> x1 >> x2;
	cout << "the larger one is : " << (x1 > x2 ? x1 : x2) << endl;
	return 0;
}
