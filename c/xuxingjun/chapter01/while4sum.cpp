#include <iostream>
using namespace std;

int main()
{
	char flag = 'y';
	while ('y' == flag) {
		cout << "Enter numbers" << endl;
		int sum = 0, n = 0;
		char c = '\0';
		// 重点讲解get与unget
		while ((c=cin.get()) != '\n') {
			cin.unget();
			cin >> n;
			sum += n;  //等价于sum = sum + n;
		}
		cout << "the sum is " << sum << endl;
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
