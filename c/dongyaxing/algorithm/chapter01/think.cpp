#include<iostream>
#include<math.h>
using namespace std;
int main()
{	
	int n=2;
	//bool flag=true;
	while(n*log(n)<1000)
	{
		n++;
	}
	cout<<"此时n= "<<n<<endl;
	return 0;
}
