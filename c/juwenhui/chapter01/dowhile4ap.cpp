#include <iostream>
using namespace std;

int main()
{
	char flag = 'y';
	do {
		cout << "Enter one number n(n >= 0)" << endl;
		int sum = 0, n = 0, start = 1;
		cin >> n;
		while (start <= n) {
			sum += start;  //等价于sum = sum + start;
			start++;       //注意与++start;的区别
		}
		cout << "the sum from 1 to " << n << " is : " << sum << endl;
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
	} while ('y' == flag);

	return 0;
}
