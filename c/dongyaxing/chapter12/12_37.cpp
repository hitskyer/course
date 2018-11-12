class Account
{
public:
	//构造函数
	Account(std::string own, double amnt)
	{
		owner = own;
		amount = amnt;
	}
	//当前本息和（余额）
	void applyint()
	{ amount += amount * interestRate; }
	//获得当前利率
	static double rate()
	{ return interestRate; }
	//重置利率
	static void rate(double newRate)
	{ interestRate = newRate; }
	//存款
	double deposit(double amnt)
	{
		amount += amnt;
		return amount;
	}
	//取款
	bool withdraw(double amnt)
	{
		if(amount < amnt)
			return false;
		else
		{
			amount -= amnt;
			return true;
		}
	}
	//获得当前余额
	double getBalance()
	{ return amount; }
private:
	std::string owner;
	double amount;
	static double interestRate;
};

double Account::intersetRate = 2.5;//一般在.cpp文件中定义


