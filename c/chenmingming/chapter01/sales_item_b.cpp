#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item book1, book2;//read info
	std::cin >> book1 >> book2;//write info
	std::cout << book1 + book2 << std::endl;
	return 0;
}
