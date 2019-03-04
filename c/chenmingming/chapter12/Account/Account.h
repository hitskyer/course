#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
// using namespace std;
class Account
{
public:
	Account(std::string own, double amnt)
	{
		owner = own;
		amount = amnt;
	}
	void applyint()	//计算余额
	{
		amount += amount * intersetRate;
	}
	static double rate()	//返回当前利率
	{
		return intersetRate;
	}
	static void rate(double newRate)	//设置新的利率
	{
		intersetRate = newRate;
	}
	double deposit(double amnt)	//存款
	{
		amount += amnt;
		return amount;
	}
	bool withdraw(double amnt)	//取款
	{
		if(amount < amnt)
			return false;
		else
		{
			amount -= amnt;
			return true;
		}
	}
	double getBalance()	//查询余额
	{
		return amount;
	}
private:
	std::string owner;
	double amount;
	static const int a = 1;
	static const char bkground = '!';	//static const 整型可以直接在类内定义初始化
	//--------------------------------------
	static double intersetRate;
	const static double initrate;
	static const std::string s1;
	static const float f1;		//static const 非整型and static 普通成员，要在类内声明，在类外初始化
};
double Account::intersetRate = 0.025;
const double Account::initrate = 0.01;
const std::string Account::s1 = "china";
const float Account::f1 = 1.0;

#endif