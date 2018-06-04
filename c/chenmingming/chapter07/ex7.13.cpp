#include<iostream>
using namespace std;
int f1(const int a[],size_t n)
{
	int res=0;
	for(size_t i =0;i != n;++i)
	{
		res += a[i];
	}
	cout << "sum of all element are " << res << endl;
}
int f2(const int *begin,const int *end)
{
	int res1=0;
	while(begin != end)
	{
		res1 += *begin++;
	}
	cout << "sum of all element are " << res1 << endl;
}
int f3(int *begin,size_t m)
{
	int res2=0;
	int *p = begin;
	while(p != begin+m)
	{
		res2 += *p++;
	}
	cout << "sum of all element are " << res2 << endl;
}
int main()
{
	int arr[]={1,2,3};
	f1(arr,sizeof(arr)/sizeof(*arr));
	f2(arr,arr+sizeof(arr)/sizeof(*arr));
	f3(arr,sizeof(arr)/sizeof(*arr));
	return 0;
}
