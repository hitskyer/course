#include<iostream>
using namespace std;

int main()
{
	const size_t array_size=10;
	int ia[array_size];
	for(size_t i=0; i<array_size;++i)
	{
		ia[i]=i+1;
		cout << ia[i] << "\n";
	}
	return 0;
}
