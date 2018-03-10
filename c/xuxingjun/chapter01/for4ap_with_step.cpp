#include <iostream>
using namespace std;

int main()
{
	char flag = 'y';
	while ('y' == flag) {
		int n = 0;
		cout << "Enter one number n(n >= 0)" << endl;
		cin >> n;
		cout << "Enter the step" << endl;
		int step = 0;
		cin >> step;
		int sum = 0;
		for (int i = 1; i <= n; i+=step) //{
			sum += i;  //等价于sum = sum + i;
		//}
		cout << "the sum from 1 to " << n << " with step " << step << " is : " << sum << endl;
		while (true) {
			cout << "continue(y/N)?" << endl;
			cin >> flag;
			if ('y' == flag) {
				break;
			} else if ('N' == flag) {
				return 0;
			} else {
				continue;
			}
		}
	}
	return 0;
}
