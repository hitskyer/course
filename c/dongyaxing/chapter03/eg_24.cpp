#include <iostream>
#include <string>
//#include <vector>
#include<bitset>
using namespace std;

int main()
{
	bitset<32> bitvec;
	int x=0,y=1,z;
	z=x+y;
	while(z<=21)
	{
		bitvec.set(z);
		x=y;
		y=z;
		z=x+y;
	}
	cout<<bitvec<<endl;
	return 0;
}
