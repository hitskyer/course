#include <iostream>
#include <string>
using namespace std;

int main()
{
	int str[]={1,2,3,4,5,6,7};
	const size_t array_size=7;
	int stra[array_size];
	
	for (size_t ix=0;ix<array_size;++ix)
	{	stra[ix]=str[ix];
		cout << stra[ix] << " ";
	}
	return 0;
}
	
	
