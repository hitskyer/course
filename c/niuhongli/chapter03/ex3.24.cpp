#include<iostream>
#include<string>
#include<bitset>
using namespace std;

int main()
{
	bitset<32> bv(0x20212e);
	cout << bv << endl;
//way 2:
	bitset<32> bvec;
	int x=0,y=1;
	int z=x+y;
	while (z<=21)
	{
	 bvec.set(z);
	 x=y;
	 y=z;
	 z=x+y;	
	}
	cout << bvec << endl;
}
