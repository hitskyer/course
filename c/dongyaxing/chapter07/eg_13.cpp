#include<iostream>

using namespace std;

int print_1(const int *beg,const int *end);
int print_2(const int a[], size_t size);
int print_3(int *begin,size_t size);


int main()
{
	int arr[5]={1,2,3,4,5};
	cout<<print_1(arr,arr+5)<<endl;
	cout<<print_2(arr,sizeof(arr)/sizeof(*arr))<<endl;
	cout<<print_2(arr,5)<<endl;
	cout<<print_3(arr,sizeof(arr)/sizeof(*arr))<<endl;
	cout<<print_3(arr,5)<<endl;
	return 0;
}
int print_1(const int *beg,const int *end)
{
	int sum=0;
	while(beg!=end)
	{
		sum+=*beg;
		beg++;
	}
	//cout<<sum<<endl;
	return sum;
}

int print_2(const int a[], size_t size)
{	
	int sum=0;
	for(size_t i=0;i!=size;++i)
	{
		sum+=a[i];
	}
	//cout<<sum<<endl;
	return sum;
}

int print_3(int *begin, size_t size)
{
	int sum=0;
	int *p=begin;
	while(p!=(begin+size))
	{
		sum+= *p;
		p++;
	}
	//cout<<sum<<endl;
	return sum;
}




