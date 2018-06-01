#include <iostream>
using namespace std;
#include "ExampleForExtern.h"

int main() {
	extern const int g_example_for_const;
	cout << "g_example_for_extern = " << g_example_for_extern << endl;
	cout << "g_example_for_const  = " << g_example_for_const << endl;
//	cout << "g_example            = " << g_example << endl;
	return 0;
}
