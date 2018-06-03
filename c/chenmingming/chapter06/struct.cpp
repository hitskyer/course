#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	int num;
	char *name;
	char sex;
	float score;	
}boy={102,"Zhang Ping",'M',78.5},*p;

int main()
{
	p=&boy;
	cout << boy.num << boy.name << endl;
	cout << boy.sex<< boy.score << endl;
	cout << (*p).num << (*p).name << endl;
	cout << (*p).sex << (*p).score << endl;
	cout << p->num << p->name << endl;
	cout << p->sex << p->score << endl;
	
}
