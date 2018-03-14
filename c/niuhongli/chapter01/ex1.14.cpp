#include <iostream>
using namespace std;

int main() 
{
	cout << "Enter two numbers : " << endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2; // read input
	// use smaller number as lower bound for summation
	// and larger number as upper bound
	int lower = 0, upper = 0;
	if (v1 <= v2) {
		lower = v1; upper = v2;
	} else {
		lower = v2; upper = v1;
	}
	int sum = 0;
	// sum values from lower up to and including upper
	for (int val = lower; val <= upper; ++val)
		sum += val; //sum = sum +val
	cout << "Sum of " << lower
		<< " to " << upper
		<< " inclusive is "
		<< sum << endl;
	return 0;
}
