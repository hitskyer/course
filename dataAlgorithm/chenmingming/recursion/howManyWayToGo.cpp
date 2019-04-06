#include <iostream>
using namespace std;
int cal(int n)
{
	if(n=1)
		return 1;
	if(n=2)
		return 2;
	return cal(n-1)+cal(n-2);
}
int main()
{
	cout << cal(39);
	return 0;
}
