#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *pArray = new int [5];
	pArray[4] = 1;
	int *pInt = &pArray[3];
	int x = *pInt;
	*pInt = 2;
	delete [] pArray;
	
	return 0;
}
