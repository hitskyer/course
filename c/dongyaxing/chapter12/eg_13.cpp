#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
class Screen
{
public: //size_type 可改写为 index
	typedef string ::size_type index;
	
	char get() const 
	{
		return contents[cursor];
	}

	inline char get (index ht, index wd) const;

	index get_cursor() const;

	Screen(index hght, index wdth, const string &cntnts);

	//增加三个成员函数
	Screen& move(index r, index c);
	Screen& set(char);
	Screen& display(ostream &os);
	//const Screen& Screen::dispaly(ostream &os) const;

private:
	string contents;
	index cursor;
	index height,width;
};
//构造函数
Screen::Screen(index hght, index wdth, const string &cntnts=""):
	cursor(0), height(hght), width(wdth)
{
	contents.assign(hght*wdth, ' ');//将括号内容，赋值给contents
	if(cntnts.size()!=0)
	contents.replace(0,cntnts.size(),cntnts);
}

Screen::~Screen()
{
}

char Screen :: get (index r, index c) const
{
	index row = r*width;
	return contents[row+c];
}

inline Screen::index Screen::get_cursor() const
{
	return cursor;
}
//增加的三个成员函数的定义
Screen& Screen::set(char c)
{
	contents[cursor]=c;
	return *this;
}
Screen& Screen::move(index r, index c)
{
	if(r>=height || c>=width)
	{
		cerr<<"invalid row or colum"<<endl;
		throw EXIT_FAILURE;
	}
	index row=r*width;
	cursor=row+c;
	return *this;
}
Screen& Screen::display(ostream &os)
{
	string :: size_type index=0;
	while(index != contents.size())
	{
		os<<contents[index];
		if((index+1)%width==0)
		{
			os<<"\n";
		}
		++index;
	}
	return *this;
}
/*const Screen& Screen::dispaly(ostream &os) const
{
	string ::size_type index=0;
        while(index != contents.size())
        {
                os<<contents[index];
                if((index+1)%width==0)
                {
                        os<<"\n";
                }
                ++index;
        }
	return *this;
}*/

int main()
{
	Screen myScreen(5,6,"aaaa\naaaaa\naaaaa\n");
	myScreen.move(4,0).set('#').display(cout);
	return 0;
}





