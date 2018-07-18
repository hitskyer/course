#include<iostream>
#include<stdlib.h>
using namespace std;

int main(int argc, char **argv )
{
	if(argc!=3)
	{
		cout<<"you should use three arguements!"<<endl;
		return -1;
	}
	cout<<"Summation of "<<argv[1]<<" and "<<argv[2]<<" is "<<(atof(argv[1])+atof(argv[2]))<<endl;	
	return 0;
}
