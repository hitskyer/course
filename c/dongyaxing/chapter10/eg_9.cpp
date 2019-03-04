#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string, int>wordCount;
	string word;
	cout<<"Enter some words(ctrl+d to end):"<<endl;
	while(cin >> word)
		++wordCount[word];

	cout<<"word\t\t"<<"times"<<endl;
	for(map<string, int>::iterator iter = wordCount.begin();iter!=wordCount.end();++iter)
		cout<<(*iter).first<<"\t\t"<<(*iter).second<<endl;
	cout<<endl;
	return 0;
}
