 #include "stdafx.h"
 #include <string>
 #include<iostream>
 //using std::string;
 //using std::cout;
 //using std::cin;
 //using std::endl;
 using namespace std;

 int main()
 {
 	string s1="hello";
	string s2="world";
	string s3=s1+ "," +s2;
	cout << s3 << endl;
	string::size_type t=0;
	t=s1.size();
	cout << t << endl;
	s3=(s1>s2)?s1:s2;
	cout << s3 << endl;
	string str("wHERE aRE yOU fROM ?");
	int nPunct=0,nSpace=0;
	for(string::size_type i=0;i!=str.size();i++)
	{
		if(islower(str[i]))
			str[i]=toupper(str[i])													else if (isupper(str[i]))														str[i]=tolower(str[i]);
		else if(ispunct(str[i]))														nPunct++;														else if(isspace(str[i]))														nSpace++;																													}
	cout << str << endl<<"中有空白符" << nSpace << "个,标点符号"<< nPunct << "个" << endl;						system("pause");
	return 0;															}

