#include <iostream>
using namespace std;
int main()
{
	enum week { Monday=1,Tuesday, Wednesday ,Thursday ,Friday ,Saturday ,Sunday };
	cout << Monday << Tuesday << Wednesday << Thursday << Friday << Saturday << Sunday <<endl;
	enum week1 { Monday1=8,Tuesday1, Wednesday1 ,
		Thursday1=20,Friday1 ,Saturday1 ,Sunday1 };
	cout << Monday1 << Tuesday1 << Wednesday1 << Thursday1 << Friday1 << Saturday1 << Sunday1 <<endl;
	int day=0;
	day = Monday +1;
	cout << "day = " << day << endl;
	week1 myday_haha = Friday1;
	cout << "myday is 21? right!" << myday_haha << endl;
}
