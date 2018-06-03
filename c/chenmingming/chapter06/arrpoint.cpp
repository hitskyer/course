#include<iostream>
using namespace std;
int main()
{
	int *p,i,a[10];
	p=a;
	cout << "enter 10 numbers!"<<endl;
	for(i=0;i<10;++i)
	{
		cin >> *p;
		++p;
	}
	p=a;
	for(i=0;i<10;++i,++p)
	{
		cout << *p << " ";
	}
	
	int b[3];
	p=b;
	b[0]=10;
	b[1]=20;
	b[2]=30;
	cout << *(p++) <<endl;
	cout << *++p << endl;
}
