#include <iostream>
using namespace std;

class Cal
{
private:
        double m_num1;   //不能把赋值放在类的定义里面
        double m_num2 ;  //这里直接 令 m_num1 = 0 会报错！
public:
        Cal();
        Cal(double a);
        Cal(double a ,double b);
        ~Cal();

        double Add()
        {
                return m_num1 +m_num2;
        }

        double Sub() const
        {
                return m_num1 - m_num2;
        }

        double &Multi(double &, const double &);
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

double &Cal::Multi(double &a, const double &b)
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
		{
			*a = (*a)/(*b);
			return a;
		}
}

int main()
{
        Cal ca;
        cout << "加法运算： " << ca.Add() << endl;
        double a = 55;
		Cal ca1(a);
		//ca1.Cal(a);   //这样调用构造函数会报错
		cout << "减法运算： " << ca1.Sub() << endl;
	        double b = 32;
                Cal ca2(a,b);
                cout << "加法运算： " << ca2.Add() << endl;
                cout << "乘法运算： " << ca1.Multi(a,b) << endl << endl;
		//cout << "看看a变量此时的值： " << a << endl;	
		cout << "看看返回的是什么？" << endl;
		cout << "除法运算： " << ca1.Div(&a,&b) << endl << endl;
		cout << "想一下，除法计算的结果和你想的一样吗？，a = 55,b = 32 " << endl;
		//cout << "我们看一下a变量的地址： " << &a << endl;
		//cout << "除法计算：" << *(ca1.Div(&a,&b))<< endl << endl;
		cout << "如果和你想的不一样，为什么会这样？" << endl;
		return 0;                      										 }
