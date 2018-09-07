#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	string str,s;
	vector<string> vstr;
	cout << "enter file names:(ex8.9.txt) " << endl;
	cin >> str;
	ifstream infile(str.c_str());
	if(!infile)
		return -1;
	// while(getline(infile,s))
	while(infile >> s)
		vstr.push_back(s);
	infile.close();
	cout << endl << "vector : " << endl;
	for(vector<string>::iterator iter = vstr.begin(); iter != vstr.end(); ++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}