#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
int main()
{
	int arr[10] = {};
	std::cout << arr[4]<< UINT_MAX;
	int numsofeachbucket[5];
   	memset(numsofeachbucket, 0, sizeof(numsofeachbucket));
	cout << numsofeachbucket[0] << " " << numsofeachbucket[1] << " "
	<< numsofeachbucket[2] << " " << numsofeachbucket[3] << " " << numsofeachbucket[4] << endl;
	return 0;
}
