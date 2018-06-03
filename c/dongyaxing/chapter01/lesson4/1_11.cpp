#include<iostream>
using namespace std;
int main()
{
	cout<<"input two int numbers"<<endl;
	int a,b;
	cin>>a>>b;
	if(a>=b)
	{
			while(b<=a)
			{
				cout<<a<<endl;
				a--;
			}
	}
	else
	//if(a<b)
	{	
		while(a<=b)
		{
		cout<<a<<endl;
		a++;
		}
	}
	return 0;
}
