#include <iostream>
using namespace std;

void exchange(int *a,int *b)
{
	int temp = 0;
	    temp = *a;
	    *a = *b;
	    *b = temp;
}

int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << endl;
	exchange(&a,&b);
	cout << a << " and "<< b << endl;
	return 0;
}
