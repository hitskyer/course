#include <iostream>
using namespace std;

int main()
{
	int a = 4,b =5,c = 6; 
	int *p = &a;
	cout<<" p point to "<<*p<<endl;
	int *p1 = p;
	*p = b;
	cout<<" p point to "<<*p<<endl;
	int **p2 = &p;
	**p2 = c;
	cout<<" p point to "<<*p<<endl;
	const size_t array_size = 6;
	int a1[array_size]={1,2,3,4,5,6};
	int *p3=a1;//int *p3=a1[0]	
	int i =p3[1];
	int j =p3[2];
	cout<<" i = "<<i<<endl;
	cout<<" j = "<<j<<endl;
	cout<<"a1[3] = "<<*(p3+3)<<endl;
	cout<<"a1[5]+3 = "<<(*(p3+5)+3)<<endl;
	int *p6=&a1[2],y = p6[-2];
	cout<<" y = "<<y<<endl;
	int *a1_begin = p3;
	int *a1_end = p3+array_size;
	for(;a1_begin != a1_end;a1_begin++)
	{
		cout<<*a1_begin<<" ";
	}
	cout<<endl;
	const int d = 7;
	const int *p4 = &d;//指针指向的对象是常量，指针指向的变量不可改变，指针的地址可以改变
	p4 = p ;
	cout<<"p4 point to "<<*p4<<endl;
	int e = 8;
	int const *p5 =&e;//指针是常量，不可改变指针的值，指针指向的对象可以是变量
	*p =e;
	cout<<"p5 point to "<<*p5<<endl;
	cout<<"p point to "<<*p<<endl;
	return 0;
}

		
