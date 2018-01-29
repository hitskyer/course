#include <stdio.h>
int main(int argc, char* argv[])
{
	printf("------------------------------\n感谢大家帮助，cmm完成了作业！\n");
	int x,y;
	for(x=0; x<=6; x++)
	{
		for(y=0; y<=x; y++)
		{
			printf("* ");
		}
	printf("\n");
	}
	for( ; x<=17; x++)
	{
		printf("***\n");
	}
	printf("------------------------------\n");
	return 0;
}

