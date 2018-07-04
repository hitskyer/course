#include<iostream>
using namespace std;

int sum1(const int ar[],size_t size)
{
	int sum=0;
	for (size_t i=0;i!=size;++i)
		sum +=ar[i];
	return sum;
}

int sum2(int *begin, size_t size)
{
	int sum=0;
	int *p=begin;
	while(p!=begin+size){
		sum+= *p;
		++p;
	}
	return sum;
}

int sum3(const int *begin, const int *end)
{
	int sum=0;
	while(begin!=end){
		sum += *begin;
		++begin;
	}
	return sum;
}

int main()
{
	int ia[]={0,1,2,3};
	cout << "Summarizion from sum1 is " << sum1(ia,4) << endl;
	cout << "Summarizion form sum2 is " << sum2(ia,4) << endl;
	cout << "Summarizion from sum3 is " << sum3(ia,ia+4) <<endl;
	return 0;
}

