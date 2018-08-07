#include<iostream>
using namespace std;

size_t cnt();

int main()
{
	for(size_t i=0;i!=10;i++)
		cout<<cnt()<<endl;
	return 0;
}

size_t cnt()
{
	static size_t ctr=-1;
	return ++ctr;
}
