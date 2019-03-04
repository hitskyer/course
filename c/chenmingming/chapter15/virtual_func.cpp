#include<iostream>
using namespace std;
class Base
{
public:
	virtual int fcn()
	{
		cout << "Base::fcn()" << endl;
		return 0;
	}
};
class D1:public Base
{
public:
	int fcn(int)//非虚函数，屏蔽基类Base的fcn()
	{
		cout << "D1::fcn(int)" << endl;
		return 0;
	}
	//D1继承了Base::fcn()
};
class D2:public D1
{
public:
	int fcn(int)//非虚函数，屏蔽基类D1的fcn(int)
	{
		cout << "D2::fcn(int)" << endl;
		return 0;
	}
	int fcn()//重定义的虚函数from Base
	{
		cout << "D2::fcn()" << endl;
		return 0;
	}
};
int main(int argc, char const *argv[])
{
	Base bobj;	D1 d1obj;	D2 d2obj;
	Base *bp = &bobj, *bp1 = &d1obj, *bp2 = &d2obj;
	bp->fcn();
	bp1->fcn();
	bp2->fcn();
	return 0;
}