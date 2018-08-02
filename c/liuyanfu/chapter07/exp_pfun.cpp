#include <iostream>

using namespace std;

typedef double (*pFun) (const double &,const double &);

double Add(const double &a,const double &b)
{
	return a+b;
}

double Sub(const double &a,const double &b)
{
	return a-b;
}

double Multi(const double &a,const double &b)
{
	return a*b;
}

double Div(const double &a,const double &b)
{
	if(b == 0)
	{
		cout << "除数不能为0！" << endl;
		return 0;
	}
	else
	{
		return a/b;
	}
}

double SelectFun_1(double (*fp)(const double &,const double &),const double &a,const double &b )
{
	return fp(a,b);
}

double SelectFun_2(pFun fp,const double &a,const double &b)
{
	return fp(a,b);
}

int main()
{
	//定义指针函数
	pFun fp = NULL;
	//给函数指针赋值
	fp = Add;
	double a =14.6, b = 45.2;
	//通过函数指针调用函数
	cout << a << " + " << b << " = " << fp(a,b) << endl;
	fp = Sub;
	cout << a << " - " << b << " = " << fp(a,b) << endl; 
	fp = Multi;
	cout << a << " * " << b << " = " << fp(a,b) << endl;
	fp = Div;
	cout << a << " / " << b << " = " << fp(a,b) << endl;
	//调用SelectFun1
	cout <<	SelectFun_1(Add,a,b) << endl;
	//调用SelectFun2
	cout << SelectFun_2(Sub,a,b) << endl;

	return 0;
}
