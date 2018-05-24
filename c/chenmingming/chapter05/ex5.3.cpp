#include<iostream>
using namespace std;
int main()
{
	int x;
	cout << "enter a num: " << endl;
	cin >> x;
	if(x % 2 == 0)
		cout << "x 是偶数！" << endl;
	else
		cout << "x s是奇数！" << endl;
	return 0;
}
