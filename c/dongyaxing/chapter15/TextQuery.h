#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class TextQuery
{
public:
	//类型别名
	typedef string::size_type str_size;
	typedef vector<string>::size_type line_no;
	//接口：
	void read_file(ifstream &is)
	{ store_file(is); build_map(); } 
	//run_query查询给定单词并返回单词所在的行号集合
	set<line_no> run_query(const string&) const;
	//text_line 返回输入文件中指定行号对应的行
	string text_line(line_no) const;
	line_no size() const;

private:
	//read_file所用的辅助函数
	void store_file(ifstream&);	//存储输入文件
	void build_map();		//将每个单词与一个行号集合相关联
	//保存输入文件
	vector<string> lines_of_text;

	//将单词与出现该单词的行的行号集合关联起来
	map<string, set<line_no> >word_map;
	
	//去掉标点并将字母变成小写
	static string cleanup_str(const string&);
	
};
#endif


