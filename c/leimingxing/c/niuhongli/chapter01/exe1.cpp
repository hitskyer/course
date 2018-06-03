#include <iostream>
/*Simple main function: read two numbers and write their sum */
int main()
{
// Prompt users to enter two numbers
std::cout << "Enter two numbers:" << std::endl;
int v1, v2;  // uninitialized 
std::cin >> v1 >> v2;  // read input
std::cout << "The sum of " << v1 << v2 << " and " << v2
          << " is " << v1 + v2 << std::endl;
return 0;
}
