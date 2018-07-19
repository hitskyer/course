#include<iostream>
using namespace std;

int swap2(int &a, int &b, int &minval)
{
	int temp = a;
	      a  = b;
	      b  = temp;
	return minval = a<b?a:b;
}
int add(const int &a,const int &b,int &result)
{
	return result = a + b;
}
int add1(int &a, int &b,int &result)
{
	return result = a + b;
}
int main()
{
	int a = 10;
	int b = 5;
	int c = 0;
	double a1 = 10.5;
	double b1 = 0.5;
	cout << "交换之前的结果：" << "a= " << a <<"  " << "b= " << b <<endl;
	swap2(a,b,c);
	cout << "交换完的结果：" << "a= " << a <<"  " << "b= " << b <<endl;
	cout << add(45,15,a) << endl;
	cout << add(a1,b1,c) << endl;
	//cout << add1(45,5,b) << endl;
	return 0;
}
