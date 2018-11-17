struct NoName
{
	NoName()::pstring(new std::string),i(0),d(0) { }
private:
	std::string *pstring;
	int i;
	double d;
};

//复制构造函数----方式一
NoName::NoName(const NoName& other)
{
	pstring = new std::string;
	*pstring = *(other.pstring);
	i = other.i;
	d = other.d;
}

//复制构造函数----方式二
NoName::NoName(const NoName& other):
pstring(new std::string(*(other.pstring))),i(other.i),d(other.d) { }

//赋值操作符
NoName& NoName::operator = (const NoName& rhs)
{
	pstring = new std::string;
	*pstring = *(rhs.pstring);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

//析构函数
NoName::~NoName()
{
	delete pstring;  //撤销pstring所指向的string对象
	pstring = NULL;   //删除后的指针，内容为随机值，必须赋值为NULL，否则会成为“野指针”
	//如果在定义p的那个函数在delete了p后，没再调用p，就没什么问题，在这个函数结束后，
	//p就会跟其它变量一样被消除。但若在那个函数里delete了p后，又没再给p赋值（地址值），
	//再次调用p就危险了，因为这时p在内存里乱指，有可能指到一些重要地址，随时可能系统崩溃。
}
