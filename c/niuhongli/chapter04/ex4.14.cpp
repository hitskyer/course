#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("Father"),s2("Mother");
	string *pi1=&s1,*pi2=&s2;
	cout << "pi1= " << *pi1 << " s1=" << s1 << endl;
	pi1=pi2;
//修改指针的值
	cout << "pi1= " << *pi1 << " s1=" << s1 << endl;
//修改指针指向对象的值
	string s3="Sister";
	string *pi=&s3;
	*pi="bro";
	cout << "pi = " << pi << " s3= " << s3 << endl;
}
