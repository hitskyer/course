class U_Ptr
{
	friend class HasPtr;	//将HasPtr类指定为U_Ptr类的友元
	int *ip;
	size_t use;
	U_Ptr(int *p):ip(p),use(1) { }
	~U_Ptr() { delete ip; }
};

//定义HasPtr类
class HasPtr
{
public:
	//构造函数：p是指向已经动态创建的int对象的指针
	HasPtr(int *p, int i):ptr(new U_Ptr(p)),val(i) { }
	
	//复制构造函数：复制成员并将使用计数 +1
	HasPtr(const HasPtr &orig):ptr(orig.ptr), val(orig.val) { ++ptr->use; }

	//赋值操作符
	HasPtr& operator = (const HasPtr&);

	//析构函数：如果使用计数为0，则删除U_Ptr对象
	~HasPtr() { if(--ptr->use == 0) delete ptr; }

	//获取数据成员
	int *get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }

	//修改数据成员
	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }
	
	//返回或修改基础int对象
	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int i) { *ptr->ip = i; }
	
private:
	U_Ptr *ptr;
	int val;
	
};

HasPtr& HasPtr::operator = (const HasPtr &rhs)
{
	//增加右操作数中的使用计数
	++rhs.ptr->use;
	//将左操作数对象的使用计数减1
	//若该对象的使用计数减至0，则删除该对象
	if(--ptr->use == 0)
	{ delete ptr; }
	ptr = rhs.ptr;	//复制U_Ptr指针
	val = rhs.val;	//复制int成员
	return *this;
}
