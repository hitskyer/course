#include<iostream>
#include<string>




class Screen
{
public:
	//使用类型别名来简化类
	typedef std::string::size_type index;
	//重载函数（类型或参数不同）
	char get() const { return contents[coursor]; }
	inline char get(index ht, index wd) const;    //内联函数

	index get_cursor() const;

	//返回类型为Screen&  知名该成员函数返回其自身类类型的对象的引用
	Screen& move(index r, index c);
	Screen& set(char);
	Screen& set(index, index, char);


	Screen& move(index r, index c);

	Screen& dispaly(std::ostream &os)
	{ do_dispaly(os); return *this; }

	const Screen& dispaly(std::ostream &os);
	{ do_dispaly(os); return *this; }

private:
	std::string contents;
	index cursor;
	index height, width;

	void do_display(std::ostream &os) const
	{ os << contents; }

};

//内联函数的三种形式
char Screen::get(index r, index c) const
{
	index row = r*width;
	return contents[row + c];
}

inline Screen::index Screen::get_cursor() const
{
	return cursor;
}

//使用this指针来访问该对象。 this 是一个指向非const的Screen的指针。
Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen& Screen::move(index r, index c)
{
	index row = r*width;
	cursor = row + c;
	return *this;
}
int main()
{	
	Screen myscreen;  //定义类型对象

	char ch_1 = myscreen.get();    //调用不同的重载函数
	char ch_2 = myscreen.get(0, 0);


	//myscreen.move(4, 0);
	//myscreen.set('#');

	//等价于
	myscreen.move(4, 0).set('#');

	myscreen(5, 3);
	const Screen blank(5, 3);
	myscreen.set('#').display(cout);  //nonconst version
	blank.display(cout);              //const version



	return 0;
}
