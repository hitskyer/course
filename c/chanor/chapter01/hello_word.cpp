#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int i;
	int j;
	//first
	int n = 4;
	for (i = 0; i<=n; i++)
	{
		for (j = n; j>i; j--)
			printf(" ");
		for (j = 0; j<=2*i; j++)
			printf("%s","*");
		for (j = n; j>i; j--)
			printf(" ");
		printf("\n");
	}
	//sec
	 n = 4;
	for (i = 2; i<=n; i++)
	{
		for (j = n; j>i; j--)
			printf(" ");
		for (j = 0; j<=2*i; j++)
			printf("%s","*");
		for (j = n; j>i; j--)
			printf(" ");
		printf("\n");
	}
	for (i = 0; i<=n; i++)
	{
		for (j = n; j>0; j--)
			printf(" ");
		printf("*\n");
	}
	return 0;
}
