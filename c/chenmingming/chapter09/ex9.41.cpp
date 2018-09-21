#include<string>
#include<iostream>
using namespace std;
string greet(string sentence, string name, string title, string::size_type pos, int length)
{
	string::size_type beg, end;
	beg = sentence.find("Daisy");
	sentence.replace(beg,5,name);
	beg = sentence.find("Ms");
	sentence.replace(beg,2,title.substr(pos,length));
	return sentence;
}
int main()
{
	string lastname("AnnaP");
	string generic1("Dear Ms Daisy:");
	string generic2("MrsMsMissPeople");
	string res = greet(generic1,lastname,generic2,5,4);
	cout << res << endl;
	return 0;
}