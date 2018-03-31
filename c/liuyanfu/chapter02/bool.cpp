#include <iostream>
using namespace std;


	void print(void * c)
	{
		bool *d;
		d=(bool*)c;
		cout << *d << endl; 
	}
	bool a;
	int main()
	{
		bool b;
		print(&b);
		print(&a);
		b=0;
		print(&b);
		b=1;
		print(&b);
		b=2;
		print(&b);
		return 0;
	}
