#include <iostream>
#include "a.h"
using namespace std;
int test()
{
	//extern const int weekday;
//	int x = weekday +1;
//	cout << weekday << endl;
	extern int year;
	cout << "year = " << year << endl;
	return 0;
}
