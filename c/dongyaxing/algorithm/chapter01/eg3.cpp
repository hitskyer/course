#include<iostream>
#include<math.h>

using namespace std;
int main()
{
	cout<<"当n为何值时，100n^2<2^n ?"<<endl;
	int n=2;
	bool flag=true;
	while(flag)
	{
		if((100*n*n-2^n)<0)
		{	flag=false;}
		++n;
	}
	cout<<"当n= "<<n<<" 时，100n^2<2^n ."<<endl;
	return 0;
}
