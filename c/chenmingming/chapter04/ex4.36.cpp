#include<iostream>
using namespace std;
int main()
{
	const int row = 3;
	const int column = 4;
	int arr[row][column]={
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11},
		};
	int (*p)[column] = arr;
	for(;p!=arr+row;++p)
		for(int *q = *p; q!= *p+column;++q)
			cout << *q << endl;
}
