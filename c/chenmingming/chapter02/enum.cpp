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
	week1 goodday;
	cout << "goodday is " << goodday << endl;
	//week1 badday = 9;  //error
	//cout << "badday is " << badday << endl;
	
	week1 day1,day2;
	cout << "day1 is " << day1 << "day2 is "<< day2 << endl;
	week1 day3,day4=Monday1;
	cout << "day3 is " << day3 << "day4 is "<< day4 << endl;
	enum year { a,b=5,c};
	cout << "a is " << a << " b is "<< b << " c is "<< c << endl;

}
