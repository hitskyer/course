class Employee
{
public:
	Employee(std::string str):name(sr), id(counter) { };  //复制函数
	Employee():name("NoName"),id(counter) { ++counter; }  //构造函数
	Employee(const Employee& other):name(other.name),id(counter){ ++counter; }  //赋值函数
	Employee& operator = (const Employee& rhe) { name = rhe.name; return *this; }   //赋值操作符

	~Employee();
	
	
private:
	std::string name;
	int id;
	static int counter;
};

//方案二

int Employ::counter = 1;
class Employee
{
public:
	//构造函数
	Employee():name("NoName") { setId(); }
	Employee(std::string nm):name(nm) { setId(); }
	Employee(const Employee& other): name(other.name) { setId(); }
	//赋值操作符 =
	Employee& operator = (const Employee& rhe)
	{
		name = rhe.name;
		return *this;
	}
private:
	std::string name;
	std::string id;
	static int counter;
	//设置雇员ID
	void setId()
	{
		id = "Empl-";
		if(counter<10)
			id += "000";
		else if(counter<100)
			id += "00";
		else if(counter<1000)
			id += "0";
		else
			std::cerr<<"no calid employee id!"<<std::endl;
	

		char buffer[5];
		_itoa(counter, buffer, 10);
		id += buffer;
		++counter;
	}
};
