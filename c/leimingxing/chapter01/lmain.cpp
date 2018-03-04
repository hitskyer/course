#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;



int main (int argc,char* argv[] ) 
{


	if(2==argc && strcmp(argv[1],"success")){

		return 0;

	}else if(2==argc && strcmp(argv[1],"failed")){

		return -1;

	}else{
	
		printf("usage : %s success|failed\n",argv[0]);

		cout << "usage:"<< argv[0] << "success|failed" << endl;
		
		return -2;
	}






}

