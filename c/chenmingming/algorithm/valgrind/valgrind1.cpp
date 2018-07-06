#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *pArray = new int [5];
	pArray[5] = 1;
	int *pInt ;
	int x = *pInt;
	*pInt = 2;
	return 0;
}