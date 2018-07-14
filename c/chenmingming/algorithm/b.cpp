#include<iostream>
using namespace std;
int main()
{
	int *p = new int [10];
	int *a = p;
	p++;
	cout << p << endl << *p << endl; //<< **p ;
	delete [] a;
	p = NULL;
	a = NULL;
	int *arr = new int [5];
	arr[0] = 3;
	arr[1] = 5;
	arr[2] = 2;
	arr[3] = 9;
	arr[4] = 10;
	cout << arr[2] << endl;
	++arr;
	cout << arr[2] << endl;
	return 0;
}
