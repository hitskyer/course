#include <iostream>
#include "AC.h"

using namespace std;


int main()
{
	AC ac;
	ac.insert("hello");
	ac.insert("world");
	ac.insert("browse");
	ac.insert("snake");
	ac.insert("he");
	ac.insert("her");
	ac.insert("wor");
	ac.insert("br");
	ac.buildFailurePointer();
	if(ac.find("hello"))
		cout << "I find it" << endl;
	else
		cout << "I not find it" << endl;

	if(ac.find("bro"))
		cout << "I find it" << endl;
	else
		cout << "I not find it" << endl;

	ac.print("hero");
	ac.print("brrowed");
	ac.print("hench");
	ac.print("redcolor");
	return 0;
}