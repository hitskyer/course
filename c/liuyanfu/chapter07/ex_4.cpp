#include <iostream>
using namespace std;

int Abs(int a)
{
	return a<0?-a:a;
}

int main()
{
	int a = 0;
	cin >> a;
	cout << endl;
	cout << a << " 的绝对值为： "<< Abs(a) << endl;
	return 0;
	
}
