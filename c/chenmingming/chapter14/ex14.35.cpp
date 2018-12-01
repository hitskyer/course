#include <iostream> //ex14.35
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
bool isShorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
class BET_cls
{
public:
    BET_cls(string::size_type len1,string::size_type len2)
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
    bool operator()(const string &s)
    {
        return s.size() >= minLength && s.size() <= maxLength;
    }
private:
    string::size_type minLength,maxLength;
};
string make_plural(size_t ctr,const string &word,const string &ending)
{
    return (ctr == 1)?word:word+ending;
}
int main(int argc,char** argv)
{
    if(argc<2)
    {
        cerr << "no input file!" << endl;
        return EXIT_FAILURE;
    }
    ifstream inputfile;
    inputfile.open(argv[1]);
    if(!inputfile)
    {
        cerr << "can not open input file!" << endl;
        return EXIT_FAILURE;
    }
    vector<string> words;
    string word;
    while(inputfile >> word)
        words.push_back(word);
    sort(words.begin(),words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
    stable_sort(words.begin(),words.end(),isShorter);
    vector<string>::size_type wc = count_if(words.begin(),words.end(),BET_cls(1,10));
    cout << wc << " " << make_plural(wc,"word","s") << " are of sizes 1 through 10 inclusive" << endl;
    return 0;
}