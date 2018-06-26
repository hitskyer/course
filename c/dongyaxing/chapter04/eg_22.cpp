#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	const int str_size=80;
	char *str1,*str2;

	str1=new char[str_size];
	str2=new char[str_size];
	if(str1==NULL || str2==NULL)
	{
		cout<<"No elements"<<endl;
		return -1;
	}
	cout<<"Enter two strings"<<endl;
	cin>>str1>>str2;

	int result;
	result = strcmp(str1,str2);
	if(result>0)
	{
		cout<<"str1 is bigger than str2"<<endl;
	}
	else if(result<0)
	{
		cout<<"str2 is bigger than str1"<<endl;
	}
	else
	{
		cout<<"str1 is equal to str2"<<endl;
	}
	delete [] str1;
	delete [] str2;
	return 0;
}



