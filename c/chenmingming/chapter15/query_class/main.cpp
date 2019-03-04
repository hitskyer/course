#include "query.h"
#include "TextQuery.h"
#include "AddQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "BinaryQuery.h"
#include "WordQuery.h"
#include "Query_base.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>
using namespace std;

//单词加后缀函数
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1)?word:word+ending; //多个单词，后缀加s
}

//打印某字符对应所有行的文本函数
void print_results(const set<TextQuery::line_no> &locs, const TextQuery &file)
{
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = locs.size();	//字符串的行号有多少个
    cout << "match occurs " << size << " " << make_plural(size, "time", "s") << endl;
    line_nums::const_iterator it = locs.begin();
    for(;it != locs.end();++it)		//遍历行号set
    {
        cout << "\t(line " << (*it)+1 << ") " << file.text_line(*it) << endl;
        //输出每个行号对应的文本
    }
}
int main(int argc, char **argv)
{
    if(argc < 2)	//判断输入文本名称参数没有
    {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
    ifstream infile;
    infile.open(argv[1]);
    if(!infile)		//判断文件打开了没有
    {
        cerr << "can not open input file!" << endl;
        return EXIT_FAILURE;
    }
    TextQuery tq;	//定义文本查询对象tq
    tq.read_file(infile);	//读取文件（存储，生成map数据库）
    typedef set<TextQuery::line_no> line_nums;
    string str1("cmm"),str2("nhl"),str3("love");
    query q = query(str1) & query(str2) | query(str3);
    const line_nums &locs = q.eval(tq);
    cout << "\nExecuted query for:" ;
    cout << q << endl;
    print_results(locs,tq);	
    return 0;
}