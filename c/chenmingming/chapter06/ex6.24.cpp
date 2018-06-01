#include<iostream>
#include<bitset>
#include<stdexcept>
using namespace std;
int main()
{
	bitset<100> bs;
	for(size_t ix=0;ix != bs.size();++ix)
		bs[ix]=1;
	try
	{
		bs.to_ulong();
	}
	catch(runtime_error err)
	{
		cout << err.what() << endl;
		cout << "? what " << endl;
	}
	return 0;
}
