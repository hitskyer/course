#include <iostream>
#include "WebBrowse.h"

using namespace std;

int main()
{
	WebBrowse wb;
	wb.browseWeb("baidu");
	wb.browseWeb("google");
	wb.browseWeb("hotfax");
	cout << endl;

	wb.back();
	wb.back();
	cout << endl;

	wb.forward();
	cout << endl;

	wb.browseWeb("sohu");
	wb.back();
	return 0;
}