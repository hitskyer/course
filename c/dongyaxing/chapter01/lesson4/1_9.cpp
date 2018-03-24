#include <iostream>
using namespace std;
int main()
{
	int a,b,c,sum=0;
	cin>>a>>b;
	c=a;
	while(a<=b)
	{
		sum+=a;
		a++;
	}
	cout<<"the sum of "<<c<<" to "<<b<<" is:  "<<sum<<endl;
	//system("pause");
	return 0;
}
