#include <iostream>
using namespace std;
int main()
{
	/*int sum;
	for(int a=50;a<=100;a++)
	{
		sum+=a;
	}
	cout<<sum<<endl;*/

	int a,b,max,min;
	cin>>a>>b;
	max=a>b?a:b;
	min=a<b?a:b;
	for(;max>=min;max--)
	{
		cout<<max<<endl;
	}	

	return 0;
}
