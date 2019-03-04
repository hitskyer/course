#include<vector>
#include<iostream>

struct exmpl
{
	//默认构造函数
	exmpl()
	{
		std::cout << "exmpl()" << std::endl;
	}
	//复制构造函数
	exmpl(const exmpl&)
	{
		std::cout << "exmpl(const exmpl&)" << std::endl;
	}
	//赋值操作符
	exmpl& operator=(const exmpl& rhe)
	{
		std::cout << "operator=(const exmpl&)" << std::endl;
		return *this;
	}
	//析构函数
	~exmpl()
	{
		std::cout << "~exmpl()" << std::endl;
	}
};

void func1(exmpl obj)
{

}

void func2(exmpl &obj)
{

}

exmpl func3()
{
	exmpl obj;
	return obj;
}

int main()
{
	exmpl eobj;
	func1(eobj);
	func2(eobj);
	eobj = func3();
	exmpl *p = new exmpl;
	std::vector<exmpl> evec(3);
	delete p;
	return 0;
}