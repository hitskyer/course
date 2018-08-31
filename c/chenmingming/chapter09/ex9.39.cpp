#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string line1 = "we were her pride of 10 she named us:";
	string line2 = "benjamin, phoenix, the prodigal";
	string line3 = "and perspicacious pacific suzanne";
	string sentence = line1 + ' ' + line2 + ' ' + line3;
	string separators = " \t:,\v\r\n\f";
	string word;
	string::size_type maxlen, minlen, wordlen, count = 0;
	vector<string> longestword, shortestword;
	string::size_type startpos=0, endpos=0;
	// startpos = sentence.find_first_not_of(separators,string::npos);
	// cout << "startpos" << startpos  << " startpos==npos?? " << bool(startpos==string::npos) << endl;

	while((startpos = sentence.find_first_not_of(separators,endpos)) != string::npos)
	{
		++count;
		endpos = sentence.find_first_of(separators,startpos);
		if(endpos == string::npos)
			wordlen = sentence.size() - startpos;
		else
		{
			wordlen = endpos - startpos;
		}
		word.assign(sentence.begin()+startpos,sentence.begin()+startpos+wordlen);
		if(count ==1)
		{
			maxlen = minlen = wordlen;
			longestword.push_back(word);
			shortestword.push_back(word);
		}
		else
		{
			if(wordlen > maxlen)
			{
				maxlen = wordlen;
				longestword.clear();
				longestword.push_back(word);
			}
			else if(wordlen == maxlen)
			{
				longestword.push_back(word);
			}
			if(wordlen < minlen)
			{
				minlen = wordlen;
				shortestword.clear();
				shortestword.push_back(word);
			}
			else if(wordlen == minlen)
			{
				shortestword.push_back(word);
			}
		}
	}
	cout << "word amount: " << count << endl;
	vector<string>::iterator iter;
	cout << "the longest word: " << endl;
	iter = longestword.begin();
	while(iter != longestword.end())
		cout << *iter++ << endl;
	cout << "the shortest word: " << endl;
	iter = shortestword.begin();
	while(iter != shortestword.end())
		cout << *iter++ << endl;
	return 0;
}