#include<iostream>
using namespace std;
struct data
{
	int month;
	int day;
	int year;

}data1,data2;

struct data data3;
struct student
{
	char *name;
	char sex;
	int age;
	struct data birthday;
}stu1[2]={{"cmm\0",'n',29,8,1,1989},{"nhl\0",'m',30,1,1,1988}};
int main()
{
	struct data data4;
	data4.month = 6;
	data4.year = 2018;
	data4.day = 12;
	cout << data4.year << data4.month <<data4.day <<endl;
	struct student *p;
	p = stu1;
	cout << p->name << p->sex << p->age << endl;
	cout << p->birthday.year << p->birthday.month << p->birthday.day <<endl;
	cout << (*p).name << (*p).sex << (*p).age << endl;
}
