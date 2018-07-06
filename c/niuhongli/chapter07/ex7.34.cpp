#include<iostream>
using namespace std;

void error(const string &s, int &index, int &upperBound)
{
	cout << s <<  " " << index << "\t" << upperBound << endl;
}

void error(const string &s)
{
	cout << s << endl;
}


void error(const string &s, char &selectVal)
{
	cout << s << "\t" << selectVal << endl;
}


