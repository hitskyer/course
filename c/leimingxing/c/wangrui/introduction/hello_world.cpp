#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	printf("%s\n", argv[0]);
	if (3 == argc){
		if (0 == strcmp(argv[1], "wangrui")) {
			printf("girl!\n");
		} 
               if (0 == strcmp(argv[2], "yangwenbin")) {
			printf("boy!\n");
		} else if(0 == strcmp(argv[2], "jesus")){
                         
                        printf("God is good!\n");
                        return -1;         
                }
		printf("%s\n", argv[1]);
}
	strcpy(argv[0],argv[1]);
        printf("Love one another!\n");
	printf(" Be joyful always!\n");

	return 0;
}
