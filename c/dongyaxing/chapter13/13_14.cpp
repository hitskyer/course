#include<vector>
#include<iostream>

struct Exmpl
{
	//默认构造函数
	Exmpl() { std::cout<<"Exmpl()"<<std::endl; }
	//复制构造函数
	Exmpl(const Exmpl&)
	{ std::cout<<"Exmpl(const Exmpl&)"<<std::endl; }
	//赋值操作符
	Exmpl& operator = (const Exmpl &rhe)
	{
		std::cout<<"operator = (const Exmpl&)"<<std::endl;
		return *this;
	}

	//析构函数
	~Exmpl()
	{ std::cout<<"~Exmpl()"<<std::endl; }
};

void func1(Exmpl obj)
{
}

void func2(Exmpl& obj)
{
}

Exmpl func3()
{
	Exmpl obj;
	return obj;
}

int main()
{
	Exmpl eobj;  //调用默认构造函数
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;
	
	func1(eobj); // 调用复制构造函数
			//将形参Exmpl对象创建为实参Exmpl对象的副本
			//函数执行完毕后，调用析构函数撤销形参Exmol对象
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;

	func2(eobj);    //形参为Exmpl对象的引用，无需调用复制构造函数传递实参
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;
	
	eobj = func3();  //调用默认构造函数创建局部Exmpl对象
			//函数返回时调用复制构造函数创建作为返回值副本的Exmpl对象
			//然后调用析构函数撤销局部Exmpl对象
			//然后调用复制操作符，
			//执行完赋值操作后，
			//调用析构函数撤销作为返回值副本的Exmpl对象
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;

	Exmpl *p = new Exmpl;  //调用默认构造函数动态创建Exmpl对象
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;

	std::vector<Exmpl> evec(3);     //调用默认构造函数
					//创建一个临时值Exmpl对象
					//然后3次调用复制构造函数
					//将临时值Exmpl对象复制到
					//vector容器evec的每个元素
					//然后调用析构函数撤销临时值Exmpl对象
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;

	delete p;	//调用析构函数撤销动态创建的Exmpl对象
	std::cout<<"*******我是分割线********"<<std::endl<<std::endl;

	//p = NULL;
	return 0;	//evec及eobj生命周期结束，自动调用析构函数撤销
			//撤销evec需要调用析构函数3次（因为evec有3个元素）
}
