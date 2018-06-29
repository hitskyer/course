#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string currword,preword;
	cout<<"Enter some words(ctrl+z to end):"<<endl;
	while(cin>>currword)
	{
		#ifndef NDEBUG
		cout<<currword<<" ";
		#endif
		if(!isupper(currword[0]))
			continue;
		if(currword==preword)
			break;
		else
			preword=currword;

	}
	if(currword==preword && !currword.empty())
		cout<<"The repeated word: "<<currword<<endl;
	else
		cout<<"There is no repeated word that has initial capital."<<endl;
	return 0;
}
