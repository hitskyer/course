#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> book;
	string bookName;
	cout<<"enter some book name:"<<endl;
	while(cin>>bookName)
	{
		book.push_back(bookName);
	}
	cin.clear();
	string sumName;
	sumName = accumulate(book.begin(), book.end(),string("name:"));
	cout<<"book string is: "<<endl;
	cout<<sumName<<endl;
	return 0;
}
