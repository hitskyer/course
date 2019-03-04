#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<istream>

using namespace std;

void restricted_wc(ifstream &removeFile, map<string, int> &word_count)
{
	vector<string> excluded;
	string removeWord;
	while(removeFile >> removeWord)
	{
		excluded.push_back(removeWord);
	}
	cout<<"Enter text(ctrl+d to end):"<<endl;
	string word;
	while(cin >> word)
	{
		bool find = false;
		vector<string>::iterator iter = excluded.begin();
		while(iter != excluded.end())
		{	
			if(*iter == word)
			{	
				find = true;
				break;
			}
			++iter;
		}
		if(!find)
			++word_count[word];
	}
}

int main()
{
	map<string, int> wordCount;
	string fileName;
	cout<<"Enter fileName:"<<endl;
	cin>>fileName;
	ifstream exFile(fileName.c_str());
	if(!exFile)
	{
		cout<<"error:can not open file:"<<fileName<<endl;
		return -1;
	}
	restricted_wc(exFile, wordCount);
	
	cout<<"word\t\t"<<"times"<<endl;
	map<string, int>::iterator iter = wordCount.begin();
	while(iter != wordCount.end())
	{
		cout<<iter->first<<"\t\t"<<iter->second<<endl;
		++iter;
	}
	return 0;

}
