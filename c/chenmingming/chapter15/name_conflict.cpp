#include<iostream>
struct base
{
	base():mem(0){}
protected:
	int mem;
};
struct Derived:base
{
	Derived(int i):mem(i){}
	int get_mem(){return mem;}
	int get_base_mem(){return base::mem;}
protected:
	int mem;
};
int main()
{
	Derived derobj(24);
	std::cout << derobj.get_mem() << std::endl;
	std::cout << derobj.get_base_mem() << std::endl;
	return 0;
}