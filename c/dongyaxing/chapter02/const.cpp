#include <iostream>

using namespace std;

int main()
{
	const int  c_i=200;
	int i=10;
	int sum=0,sub=0,multi=0,div=0;
	sum=c_i+i;
	sub=c_i-i;
	multi=c_i*i;
	div=c_i/i;
	cout<<"sum="<<sum<<endl;
	cout<<"sub="<<sub<<endl;
	cout<<"multi="<<multi<<endl;
	cout<<"div="<<div<<endl;
	return 0;
}
