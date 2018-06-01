#include <iostream>
using namespace std;

/*
 *
 *
 *
 *
 */
class Sales_item
{
	public:
		int id;
	
	private:
		string isbn;
}
struct Sales_item
{
	int id;
	private:
		string isbn;
}

extern const int hdCount = 5;
int main()
{
	int ival = 1024;
	int &refVal = ival;
	int &refrefVal = refVal;
	int *a = &ival;
	int b = sizeof(&refVal);

	typedef  int  a_s,b_s;
	a_s a1,a2;	
	
	enum week {mon=5,tur,mar};
	week x = 7;
	cout << x;
	if (0 == mon)
	{
		cout << refVal << " | " << a << endl;
	}

}
