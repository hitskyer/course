#include<iostream>
using namespace std;

int sw_ap(int *pa,int *pb)
{
	int *px;
	px = pa;
	pa = pb;
	pb = px; 
}
int main()
{
	int a,b;
	int *p1,*p2;
	cout << "enter two numbers!" << endl;
	cin >> a >> b;
	p1=&a;
	p2=&b;
	cout << a << " " << b << " " << *p1 << " " << *p2 <<endl;
	int **p;
	p=&p1;
	cout << *p << **p <<endl;
	if(a < b)
	{
		sw_ap(&a,&b);
	}
	cout <<"a is " <<  a << " b is "<< b << endl;
}
