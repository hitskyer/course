#include<iostream>
using namespace std;
int main(int argc,char* args[])
{
	cout<< "ender two numbers " <<endl;
	int a = 0 , b = 0 ;
	cin >> a >> b;
	if(b==0)
	{
		cout << "第二个数不可为零" << endl;
		cin >> a >> b;
	}
	cout << " the div of " << a << " and " << b << " is " << a/b << endl;
	return 0;
}
