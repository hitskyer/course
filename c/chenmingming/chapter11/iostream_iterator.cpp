#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;
int main()
{
	string filename;
	cout << "enter input file name: " << endl;
	cin >> filename;
	ifstream infile(filename.c_str());
	if(!infile)
	{
		cout << "can not open file: " << filename << endl;
		return EXIT_FAILURE;
	}
	ostream_iterator<string> out_iter(cout," ");
	istream_iterator<string> in_iter(infile), eof;
	copy(in_iter,eof,out_iter);
	infile.close();
	return 0;
}