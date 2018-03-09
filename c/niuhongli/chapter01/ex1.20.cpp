#include <iostream>
using namespace std;

int main() 
{
	cout << "Enter two numbers : " << endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2; // read input
	// use smaller number as lower bound for summation
	// and larger number as upper bound
	int sum = 0;
	// sum values from lower up to and including upper
	for (int val = v1; val <= v2; ++val)
		sum += val; //sum = sum +val
	cout << "Sum of " << v1
		<< " to " << v2
		<< " inclusive is "
		<< sum << endl;
	return 0;
}
