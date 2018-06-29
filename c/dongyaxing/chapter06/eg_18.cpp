#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1,str2,str3;
	
	do
	{
		cout<<"enter two strings"<<endl;
		cin>>str1>>str2;
		if(str1>str2)
			cout<<str1<<" is more previous than "<<str2<<endl;
		else if(str1<str2)
			cout<<str2<<" is more previous than "<<str1<<endl;
		else
			cout<<str1<<" = "<<str2<<endl;
		cout<<"continue?(y-yes,n-no)"<<endl;
		cin>>str3;
	}
	while(str3[0]!='n' && str3[0]!='N');
	return 0;
}
