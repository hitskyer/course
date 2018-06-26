#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	long i,j;
	cout<<"enter two large numbers(eg:百万-亿)"<<endl;
	cin>>i>>j;
	clock_t start1,finish1;
	start1=clock();
	while(i>0)
	{
		i--;
	}
	finish1=clock();
	cout<<"time:"<<finish1-start1<<endl;
	clock_t start2,finish2;
	start2=clock();
	while(j>0)
	{
		--j;
	}
	finish2=clock();
	cout<<"time:"<<finish2-start2<<endl;
	
	return 0;
}
