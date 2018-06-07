#include <iostream>
#include <string>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	const size_t arr_size=5;
	int ia1[arr_size],ia2[arr_size];
	size_t ix;
	cout<<"Enter "<<arr_size<<" numbers for ia1"<<endl;
	for(ix=0;ix!=arr_size;++ix)
		cin>>ia1[ix];
	cout<<"Enter "<<arr_size<<" numbers for ia2"<<endl;
	for(ix=0;ix!=arr_size;++ix)
		cin>>ia2[ix];
	for(ix=0;ix!=arr_size;++ix)
	{
		cout<<ia2[ix]<<" ";
	}
	for(ix=0;ix!=arr_size;++ix)
	{
		if(ia1[ix]!=ia2[ix])
		{
			cout<<"ia1[]!=ia2[]"<<endl;
			return 0;
		}
	}
	cout<<"ia1[]=ia2[]"<<endl;
	return 0;
}



