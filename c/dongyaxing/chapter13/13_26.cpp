#include<iostream>

class HasPtr
{
public:
	//构造函数：保存指向形参副本对象的指针
	HasPtr(const int &p, int i):ptr(new int(p)), val(i) { }
	
	//复制构造函数：创建新的基础int对象，保存与被复制基础对象相同的值
	HasPtr(const HasPtr &orig):
	ptr(new int (*orig.ptr)), val(orig.val) { }

	//赋值操作符
	HasPtr& operator = (const HasPtr&);

	//析构函数
	~HasPtr() { delete ptr; }

	//获取数据成员
	int get_ptr_val() const { return *ptr; }
	int get_int() const { return val; }

	//修改数据成员
	void set_ptr(int *p) { ptr = p; }
	void set_int(int i) { val = i; }

	//返回指针成员
	int *get_ptr() const { return ptr; }
	
	//设置指针成员所指向的基础对象
	void set_ptr_val(int p) const { *ptr = p; }

private:
	int *ptr;
	int val;
};

//赋值操作符 不需要分配新对象，只是给其指针所指向的对象赋新值
HasPtr& HasPtr::operator = (const HasPtr &rhs)
{
	*ptr = *rhs.ptr;
	val = rhs.val;
	return *this;
}

int main()
{
	int obj = 0;
        HasPtr ptr1(&obj,10);
        HasPtr ptr2(ptr1);      //复制HasPtr对象
        std::cout<<ptr1.get_ptr_val()<<std::endl;               //ptr1的值为0
        std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;    //ptr2的值为0

        ptr1.set_int(22);       //只改变ptr1的值
        ptr2.get_int();         //returns 0
        ptr1.get_int();         //returns 0
        std::cout<<ptr1.get_ptr_val()<<std::endl;
        std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;

        ptr1.set_ptr_val(22);   //重置ptr1和ptr2指向的对象
        ptr2.get_ptr_val();     // 22
        std::cout<<ptr1.get_ptr_val()<<std::endl;
        std::cout<<ptr2.get_ptr_val()<<std::endl<<std::endl;

        int *ip = new int(42);
        HasPtr ptr(ip, 10);
	//std::cout<<ip.get_ptr_val()<<std::endl<<std::endl;
        delete ip;
	return 0;
}
