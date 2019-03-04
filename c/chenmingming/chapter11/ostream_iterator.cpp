#include<vector>
#include<iterator>
#include<iostream>
#include<fstream>
#include<exception>
#include<string>
using namespace std;
int main(int argc, char** argv)
{
	ifstream openfile;
	openfile.open(argv[1]);
	if(!openfile)
		throw runtime_error("open file failure!");
	ostream_iterator<string> out_iter(cout,"\n");
	istream_iterator<string> int_iter(openfile),end;
	while(int_iter != end)
	{
		*out_iter++ = *int_iter++;
	}
	return 0;
}