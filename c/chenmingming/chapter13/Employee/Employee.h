#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<fstream>
#include<iostream>
class Employee
{
public:
	//构造函数
	Employee():name("NoName")
	{
		setID();
		writeData(*this);
	}
	Employee(std::string nm):name(nm)
	{
		setID();
		writeData(*this);
	}
	Employee(const Employee& other):name(other.name)
	{
		setID();
		writeData(*this);
	}
	//赋值操作符
	Employee& operator=(const Employee& rhe)
	{
		name = rhe.name;
		return *this;
	}
private:
	std::string name;
	std::string id;
	static int counter;
	void setID()
	{
		id = "BAJY-";
		if(counter < 10)
			id += "000";
		else if(counter < 100)
			id += "00";
		else if(counter < 1000)
			id += "0";
		else
			std::cerr << "no vaild Employee id !" << std::endl;
		char buffer[5];
		_itoa(counter,buffer,10);
		id += buffer;
		++counter;
	}
	void writeData(const Employee& emp)
	{
		std::ofstream writefile;
		writefile.open("man.txt",std::ofstream::app);
		writefile << emp.id << " " << emp.name << std::endl;
		writefile.close();
	}
};
int Employee::counter = 1;
#endif

