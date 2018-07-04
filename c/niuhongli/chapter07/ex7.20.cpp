#include<iostream>
using namespace std;

int factorial(int val)
{
	int result=1;
	for(int i=1;i<=val;++i)
		result*=val;
	return result;
}
