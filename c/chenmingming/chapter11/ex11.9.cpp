#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
bool isshorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
bool gt4(const string &s)
{
	return s.size() >= 4;
}
string make_end_s(size_t ctr, const string &word,
						const string &ending)
{
	return (ctr == 1)?word:word+ending;
}
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	ifstream infile;
	infile.open(argv[1]);
	if(!infile)
	{
		cerr << "can not open input file!" << endl;
		return EXIT_FAILURE;
	}
	vector<string> words;
	string word;
	while(infile >> word)
		words.push_back(word);
	sort(words.begin(),words.end());
	words.erase(unique(words.begin(),words.end()),words.end());
	stable_sort(words.begin(),words.end(),isshorter);
	vector<string>::size_type wc = count_if(words.begin(),words.end(),gt4);
	cout << wc << " " << make_end_s(wc,"word","s")
		<< " 4 characters or longer!" << endl;
	cout << "unique words:" << endl;
	for(vector<string>::iterator iter = words.begin();
		iter != words.end();++iter)
		cout << *iter << endl;
	cout << endl;
	return 0;
}