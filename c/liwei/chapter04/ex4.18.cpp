#include<iostream>

#include<string>

using namespace std;



int main()

{

	const size_t array_size=5;

	int ia[array_size]={0,2,3,5,7};

	

	for(int *pbegin=ia,*pend=ia+array_size;pbegin<pend;++pbegin)

		cout << *pbegin << " " ;

}
