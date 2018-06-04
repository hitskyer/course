#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str_result,str;
	cin>>str_result;
	while(cin>>str)
	{
		str_result=str_result+" "+str;
		cout<<str_result<<endl;
	}
	return 0;
}
