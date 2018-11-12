#include<vector>
#include<iterator>
#include<iostream>
#include<fstream>
#include<exception>
using namespace std;
int main(int argc, char** argv)
{
	//vector<int> ivec;
	ifstream openfile;
	openfile.open(argv[1]);
	if(!openfile)
		throw runtime_error("open file failure!");
	istream_iterator<int> int_iter(openfile);
	istream_iterator<int> end;
	// while(int_iter != end)
	// {
	// 	ivec.push_back(*int_iter++);
	// 	openfile.clear();
	// }
	vector<int> ivec(int_iter,end);
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}