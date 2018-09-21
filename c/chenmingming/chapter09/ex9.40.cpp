#include<string>
#include<iostream>
using namespace std;
int main()
{
	string q1("when lilacs last in the dooryard bloom'd");
	string q2("the child is father of the man");
	string sentence;
	sentence.assign(q2,0,13);
	cout << sentence << endl;
	sentence.append(q1.substr(q1.find("in"),15));
	cout << sentence << endl;
	return 0;
}