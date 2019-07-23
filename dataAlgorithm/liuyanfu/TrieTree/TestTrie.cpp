#include <iostream>
#include <string>
#include "TrieTree.h"

using namespace std;

int main()
{
	TrieTree trie;
	string word;
	cin >> word;
	while(word != "#")
	{
		trie.insert(word.c_str());
		word.empty();
		cin.clear();
		cin >> word;
	}

	word.empty();
	cin.clear();
	cout << "please enter the word you want to query: ";
	cin >> word;
	while(word != "#")
	{
		if(trie.find(word.c_str()))
			cout << "I find it" << endl;
		else
			cout << "I not find it" << endl;
		word.empty();
		cin.clear();
		cin >> word;
	}
	return 0;
}