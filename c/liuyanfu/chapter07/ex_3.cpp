#include <iostream>
using namespace std;

int myfun (int x,int y)
{
	int result = 1;
	for (int i = 1;i <= y; ++i)
	{
		result *= x; 
	}
	return result;
}

int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << endl;
	cout << a << " 的 " << b << " 次幂为： " << myfun(a,b) << endl;  
	return 0;
}
