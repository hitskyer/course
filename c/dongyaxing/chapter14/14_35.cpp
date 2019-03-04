#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//找更小
bool isShorter(const string &str1, const string &str2)
{
	return str1.size() < str2.size();
}
//测试
class BBT_cls
{
public:
	BBT_cls(string::size_type len1, string::size_type len2)
	{
		if(len1 < len2)
		{
			minLength = len1;
			maxLength = len2;
		}
		else
		{
			minLength = len2;
			maxLength = len1;
		}
	}

	bool operator () (const string &str)
	{
		return str.size()>minLength && str.size() <= maxLength;
	}
private:
	string::size_type minLength;
	string::size_type maxLength;
};

class GT_cls
{
public:
	GT_cls(size_t val = 0):bound(val) { }
	bool operator() (const string &s)
	{
		return s.size()>bound;
	}
private:
	std::string::size_type bound;
};

//返回复数版本
string make_plura(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1)? word :word + ending;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}
	
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"can not open input file!"<<endl;
		return EXIT_FAILURE;
	}
	
	vector<string> words;
	string word;
	
	while(inFile>>word)
		words.push_back(word);
	
	//对输入排序一遍去除重复的单词
	sort(words.begin(), words.end());
	//使用算法unique对元素重新排序，并返回一个迭代器
	//表示无重复单词范围的结束
	//erase操作使用该贴袋器删除输入序列中重复的单词
	words.erase(unique(words.begin(),words.end()),words.end());

	//stable_sort(words.begin(), words.end(), isShorter);
	
	vector<string>::size_type wc = count_if(words.begin(), words.end(), BBT_cls(1,8));
	
	cout<<wc<<" "<<make_plura(wc, "word", "s")<<" are of sizes 1 through 10 inclusive"<<endl;
	
	wc = count_if(words.begin(), words.end(), GT_cls(10));
	cout<<wc<<" "<<make_plura(wc, "word", "s")<<" 10 charactere or larger "<<endl;
	return 0;
}
