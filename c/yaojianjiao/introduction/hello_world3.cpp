#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[])
{
	printf("hello welcome c++ world \n");

		printf("说明1： %s"," \%s 字符串占位符\n");
		printf("说明2： %s"," \%d 数字占位符\n");
	
	int i=0 ;

	do{
		i++;
		printf("第 %d  次 \n ", i );
		
	}while(i<5);

	return 0;
}
