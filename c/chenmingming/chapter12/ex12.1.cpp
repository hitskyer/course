class Person
{
public:
	Person(const std::string &nm, const std::string &addr):
		name(nm), address(addr) { }
	std::string getName() const
	{
		return name;
	}
	std::string getAddress() const
	{
		return address;
	}
private:
	std::string name;
	std::string address;
};