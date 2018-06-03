//#include "afu.h"
#include "afu.cpp"
#include<iostream>
using namespace std;

extern int afu_age;
extern void age();

int main()
{	
	cout<<afu_age<<endl;
	cout<<"i know "<<endl;
	age();
	return 0;
}
