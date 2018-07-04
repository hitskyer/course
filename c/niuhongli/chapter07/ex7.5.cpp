#include<iostream>
using namespace std;

int getBigger(int x, const int *y)
{
	return x > *y ? x: *y;
}


