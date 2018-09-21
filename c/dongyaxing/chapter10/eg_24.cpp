#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	set<string> excluded;
	excluded.insert("success");
	excluded.insert("class");
	
	string word;
	while(cin>>word)
	{
		if(!excluded.count(word))
			word.resize(word.size()-1);  //去掉单词末尾的s
		cout<<"non-plural version:"<<word<<endl;
		cout<<"enter a word(ctrl+d to end):"<<endl;
	}
	return 0;
}
