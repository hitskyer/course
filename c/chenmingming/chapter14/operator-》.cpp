#include <iostream>
class firstClass 
{
public:
	firstClass* operator->()
	{
		std::cout << "firstClass ->() is called!" << std::endl;
		return this;
	}

	void action()
	{
		std::cout << "firstClass action() is called!" << std::endl;
		return;
	}
};
class myClass
{
	firstClass firstObj;
public:
	firstClass& operator->()
	{
		std::cout << "myClass ->() is called!" << std::endl;
		return firstObj;
	}

	void action()
	{
		std::cout << "myClass action() is called!" << std::endl;
		return;
	}
};

int main()
{
	myClass obj;
	obj->action();
	return 0;
}
