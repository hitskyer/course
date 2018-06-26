#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	long i1=0;
	clock_t start1,finish1;
	start1=clock();
	while(i1<100000000)
	{	++i1;
	}
	cout<<i1<<endl;
	finish1=clock();
	cout<<finish1-start1<<"us"<<endl;
	/*long i2=0;
	clock_t start2,finish2;
	start2=clock();
	while(i2<100000000)
	{
		i2++;
	}
	cout<<i2<<endl;
	finish2=clock();
	cout<<finish2-start2<<"us"<<endl;*/
	return 0;
}
