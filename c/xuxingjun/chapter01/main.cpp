#include <stdio.h>
#include <iostream>
#include "string.h"
int main(int argc, char* argv[])
{
	if (2 == argc && 0 == strcmp(argv[1], "success")) {
		return 0;
	} else if (2 == argc && 0 == strcmp(argv[1], "failed")) {
		return -1;
	} else {
		printf("%s success|failed\n", argv[0]);
		std::cout << argv[0] << " success|failed" << std::endl;
		return -2;
	}
}
