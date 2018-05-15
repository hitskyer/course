#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i=42,j=1024;
	int *p1=&i,*p2=&j;
	*p2=*p1 * *p2;
	*p1*=*p1;
	cout<< "i=" <<i<< endl;

	cout << "j= " << j << endl;
	cout << "p2 = " << *p2 << endl;
	cout << "p1= " << *p1 << endl;
}
