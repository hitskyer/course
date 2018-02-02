
#include <stdio.h>
#include<string>

#include<iostream>
using namespace std;

int  main()
{
	int a[3][5]={1,2,3,4,5,6,7,8,9};
	int i=0,j=0;
	while(i<3)
 
 {
	j=0;
	while(j<5)
		{
			printf("%d ",a[i][j]);
			j++;
	 	}
	 	puts("\n");
		i++;
}
	string str1="娃哈哈";
	cout<<str1<<endl;
	return 0;
}


