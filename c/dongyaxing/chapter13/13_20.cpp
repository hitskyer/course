#include<iostream>

class HasPtr
{
public:
	//构造函数初始化
	HasPtr(int *p, int i):ptr(p), val(i) {}

	//获得成员变量
	int *get_ptr() const { return ptr; }
	int get_int() const { return val; }

	//设置成员变量
	void set_ptr(int *p) { ptr = p; }
	void set_int(int i) { val = i; }

	//获得指针内容，设置指针指向的值
	int get_ptr_val() const { return *ptr; }
	int set_ptr_val(int val) const { *ptr = val; }

private:
	int *ptr;
	int val;
};

int main()
{
	int obj = 0;
	HasPtr ptr1(&obj, 42);
	HasPtr ptr2(ptr1);	//复制HasPtr对象
	std::cout<<ptr1.get_ptr_val()<<std::endl;		//ptr1的值为0
	std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;	//ptr2的值为0
	
	ptr1.set_int(22);	//只改变ptr1的值
	ptr2.get_int();		//returns 0
	ptr1.get_int();		//returns 0
	std::cout<<ptr1.get_ptr_val()<<std::endl;
        std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;
	
	ptr1.set_ptr_val(22);	//重置ptr1和ptr2指向的对象
	ptr2.get_ptr_val();	// 22
	std::cout<<ptr1.get_ptr_val()<<std::endl;
        std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;

	int *ip = new int(42);
	HasPtr ptr(ip, 10);
	delete ip;
	
	//ptr.set_ptr_val(0);	//ptr指向的内容没有了

	return 0;
}
