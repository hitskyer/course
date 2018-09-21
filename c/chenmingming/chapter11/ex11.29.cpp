#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
int main(int argc, char **argv)
{
	if(argc<2)
	{
		cerr << "no input file!" << endl;
		return EXIT_FAILURE;
	}
	ifstream infile;
	infile.open(argv[1]);
	if(!infile)
	{
		cerr << "can not open input file!" << endl;
		return EXIT_FAILURE;
	}
	list<string> words;
	string word;
	while(infile >> word)
		words.push_back(word);
	words.sort();
	words.unique();
	cout << "unique words: " << endl;
	for(list<string>::iterator iter = words.begin();
		iter != words.end();++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}