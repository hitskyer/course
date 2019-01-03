#include "Query.h"
#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//采用10.32实现函数
string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr == 1)?word:word+ending;
}

ifstream& open_file(ifstream& in, const string& file)
{
	in.close();		//关闭已打开为文件
	in.clear();		//清除存在的错误
	in.open(file.c_str());
	return in;
}
void print_results(const set<TextQuery::line_no>& locs, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	//如果找到匹配的结果，则输出匹配的行数
	cout<<"match occurs"<<size<<" "<<make_plural(size,"time","s")<<endl;

	//输出出现该单词的每一行
	line_nums::const_iterator it = locs.begin();
	for(; it!= locs.end(); ++it)
	{
		cout<<"\t(line "<<(*it)+1<<" ) "<<file.text_line(*it)<<endl;	
	}
}

int main(int argc, char **argv)
{
	//打开要在其中进行查询的文本文件
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]))
	{
		cerr<<"No input file!"<<endl;
		return EXIT_FAILURE;
	}

	TextQuery file;
	file.read_file(infile);		//读入文本，建立map容器

	typedef set<TextQuery::line_no> line_nums;
	
	//构造查询
	Query q = Query("fiery") & Query("bird") | Query("wind");

	//计算查询，获得匹配行的行号集合
	const line_nums &locs = q.eval(file);

	//输出查询表达式
	cout<<"\nExecuted Query for: "<<q<<endl;

	//输出查询结果
	print_results(locs,file);

	return 0;
}
