#include <iostream>
#include <string>
#include <vector>
#include<bitset>
using namespace std;

int main()
{

	const size_t arr_size=5;
	int a[arr_size]={1,2,3,4,5};
	for(int *pbegin = a,*pend = a + arr_size;*pbegin != *pend;*pbegin++)
	{
		*pbegin = 0;
		//cout<<"方案一"<<endl;
		//cout<<*pbegin<<endl;
		cout<<"方案二"<<endl;
		cout<<a[*pbegin]<<endl;
	}
	return 0;
}
