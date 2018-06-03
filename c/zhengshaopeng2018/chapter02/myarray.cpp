#include <iostream>
using namespace std;
	
int main()
{
	const int array_size=4;
	int a[array_size];
	int a1[4];
	int a2[]={1,2,3,4,5};
	char a3[]={'c','+','+'};
	for(int ix = 0;ix != 5;ix++)	
	{	
		a2[ix]=ix;
		cout<<a2[ix]<<" ";
	}
	cout<<endl;
	return 0;
}

