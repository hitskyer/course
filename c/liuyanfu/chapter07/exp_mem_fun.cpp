#include <iostream>
using namespace std;

class Cal
{
private:
	double m_num1;
	double m_num2;
public:
	Cal();
	Cal(double a);
	cal(double a ,double b);
	~Cal();

	double Add(double a = m_num1,double b = m_num2)
	{
		return a+b;
	}

	double Sub() const
	{
		return m_num1 - m_num2;
	} 
	
	double &Multi(const double &, const double &);
	double *Div(double *,double *);
};

Cal::Cal()
{
	m_num1 = 10;
	m_num2 = 5;
}

Cal::Cal(double a)
{
	m_num1 = a;
	m_num2 = 9;
}

Cal::Cal(double a,double b)
{
	m_num1 = a;
	m_num2 = b;
}

Cal::~Cal()
{

}

double &Cal::Multi(const double &a, const double &b)
{
	return a = a * b;
}

double *Cal::Div(double *a, double *b)
{
	if (*b == 0)
	{
		cout << "除数不能为0！" << endl;
		return 0;
	}
	else
		return &((*a) = (*a)/(*b))
}

int main()
{
	Cal ca;
	cout << "第一个成员变量为： " << ca.m_num1 << endl;
	cout << "第二个成员变量为： " << ca.m_num2 << endl;
	int a = 55;
	ca.Cal(a);
	cout << "第一个成员变量为： " << ca.m_num1 << endl;
	cout << "第二个成员变量为： " << ca.m_num2 << endl;
	return 0;
}
