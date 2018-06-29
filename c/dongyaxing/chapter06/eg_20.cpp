#include<iostream>
#include<string>
using namespace std;
int main()
{
	string currword,preword;
	cout<<"Enter some words:(Ctrl+z to end)"<<endl;
	while(cin>>currword)
	{
		if(currword==preword)
			break;
		else
			preword=currword;
	}
	if(currword==preword && !currword.empty())
		cout<<"the repeated word:"<<currword<<endl;
	else
		cout<<"there is no repeated word."<<endl;
	return 0;
}
