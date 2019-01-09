#include "TextQuery.h"
#include <vector>
#include<fstream>
#include<sstream>
using namespace std;

//store_file函数实现
void TextQuery::store_file(ifstream &is)
{
    string textline;
    while(getline(is,textline))		//从文件流 is中获取每一行的文本，存成 n行（个）元素的 vector
        lines_of_text.push_back(textline);
}

//build_map函数实现
void TextQuery::build_map()
{
    for(line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)	//遍历 n行
    {
        istringstream line(lines_of_text[line_num]);	//定义字符串流line（绑定每行的文本）
        string word;
        while(line >> word)	//把字符串流line里的每个字符串word，和其行号line_num，存成map
            word_map[cleanup_str(word)].insert(line_num);
    }
}

//查询函数run_query实现
set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
    map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);
    //找到被查询单词的迭代器
    if(loc == word_map.end())
        return set<line_no>();	//如果找到结尾了，没找到，返回空set
    else
        return loc->second;		//如果找到了，返回迭代器指向对象的第二元素 set行号集合
}

//文本行 text_line函数，返回某行的文本
string TextQuery::text_line(line_no line) const
{
    if(line < lines_of_text.size())	//如果行号没有超出范围，返回vector里的某个元素（一行文本）
        return lines_of_text[line];
    throw std::out_of_range("line number out of range");	//行号超出，则抛出异常
}

string TextQuery::cleanup_str(const std::string &word)
{
    string ret;
    for(string::const_iterator it = word.begin();it != word.end();++it)
    {
        if(!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}
vector<string>::size_type TextQuery::size() const
{
    return lines_of_text.size();
}