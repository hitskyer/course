#include<iostream>
using namespace std;
int main()
{
	int arr[2]={5,6};
	int *p = arr;
	cout << *p << endl;
	++p;
	cout << *p << endl;
	p = &arr[0];
	*p=8;
	cout << arr[0]<< endl;
	++p;
	*p=9;
	cout << arr[1] << endl;
}
