#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	const char *str1="how are you?";
	const char *str2=" i am fine,thank you.";
	size_t len=strlen(str1)+strlen(str2);
	char *result=new char[len+1];
	strcpy(result,str1);
	strcat(result,str2);
	cout<<result<<endl;
	delete [] result;

	string str3="what is your name?";
	string str4=" li ming";
	string str5=str3+str4;
	cout<<str5<<endl;
	return 0;
}


