class Bar
{
public:
	Foo FooVal()
	{
		callsFooVal++;
		return fval;
	}

private:
	static int ival;
	static Foo fval;
	static int callsFooVal;
};

int Bar::ival = 20;
Foo Bar::fval(0);
int Bar::callsFooVal = 0;
