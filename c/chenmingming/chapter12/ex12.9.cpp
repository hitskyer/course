#include<iostream>
#include<string>
using namespace std;

class Screen
{
public:
	typedef std::string::size_type index;
	char get() const { return contents[cursor];}
	inline char get(index ht, index wd) const;
	index get_cursor() const;
	Screen(index hgth, index wdth,const string &cntnts);
	Screen& move(index r, index c);
	Screen& set(char);
	Screen& display(ostream &os);
private:
	std::string contents;
	index cursor;
	index height, width;
};
Screen::Screen(index hgth, index wdth, const string &cntnts = " "):
	cursor(0), height(hgth),width(wdth) 
{
	contents.assign(hgth*wdth, ' ');
	if(cntnts.size() != 0)
		contents.replace(0,cntnts.size(),cntnts);
}
char Screen::get(index r, index c) const
{
	index row = r * width;
	return contents[row+c];
}
inline Screen::index Screen::get_cursor() const
{
	return cursor;
}
Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
Screen& Screen::move(index r, index c)
{
	index row = r * width;
	cursor = row + c;
	return *this;
}
Screen& Screen::display(ostream &os)
{
	string::size_type index = 0;
	while(index != contents.size())
	{
		os << contents[index];
		if((index+1)%width == 0)
		{
			os << '\n';
		}
		++index;
	}
	return *this;
}

int main()
{
	Screen myscreen(5,6,"aaaaa\naaaaa\naaaaa\naaaaa\naaaaa\n");
	myscreen.move(4,0).set('#').display(cout);
	return 0;
}