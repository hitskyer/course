#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;  // read two transaction;
	std::cout << item1+item2 << std::endl; // print out the sum of two transactions;
	return 0;
}
