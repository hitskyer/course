#include<iostream>
using namespace std;
int main()
{
	int i=0;
	for(;i<10;++i)
	{
		if(i==5){
		cout << "i is " << i << endl;
		return 1;}
	}
	cout << "不能输出 i is " << i << endl;
	return 0;
}
