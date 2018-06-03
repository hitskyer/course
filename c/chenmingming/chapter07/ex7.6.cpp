#include<iostream>
using namespace std;
void myswap(int *&a,int *&b)
{
//	int *tem=0;
	int *tem = a;
	a = b;
	b = tem;
}

int main()
{
	cout << "输入两个数：" << endl;
	int u,v;
	int *x = &u,*y = &v;
	cin >> u >> v;
	cout << "交换前 " << *x << " "<< *y;
	myswap(x,y);
	cout << " 交换后 " << *x << " "<< *y << endl;
	return 0;
}
