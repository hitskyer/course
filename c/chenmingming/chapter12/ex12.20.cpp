class Date
{
public:
	Date(){}
	Date(int yy, int mm, int dd):year(yy),month(mm),day(dd){}
private:
	int year, month, day;
};

class Foo
{
public:
	Foo(int x)
	{
		value = x;
	}
	int get()
	{
		return value;
	}
private:
	int value;
};

class Bar
{
public:
	Foo FooVal()
	{
		callsFooval++;
		return fval;
	}
private:
	static int ival;
	static Foo fval;
	static int callsFooval;
};
int Bar::ival = 20;
Foo Bar::fval(0);
int Bar::callsFooval = 0;