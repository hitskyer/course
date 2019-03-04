#include<iostream>
using namespace std;
template <typename S>
S absVal(S val)
{
	return val > 0 ? val : -val;
}
int main()
{
	double dval = 0.88;
	float fval = -12.3;
	cout << absVal(-3) << endl;
	cout << absVal(dval) << endl;
	cout << absVal(fval) << endl;
	return 0;
}