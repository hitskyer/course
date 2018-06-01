#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	bitset<100> bs;
	for(size_t ix=0;ix != bs.size();++ix)
		bs[ix]=1;
	bs.to_ulong();
	return 0;
}
