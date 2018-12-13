#include"Query.h"
#include"TextQuery.h"
#include<set>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;

//返回不在其操作数结果集中的行号集合
set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const
{
	//计算其操作数的结果集
	set<TextQuery::line_no> has_val = query.eval(file);
	set<line_no> ret_lines;

	//检查输入文件中的每一行，看改行的行号是否在has_val中
	//如果不在，将该行的行号加入到ret_lines
	for(TextQuery::line_no n = 0; n != file.size(); ++n)
	{
		if(has_val.find(n) == has_val.end())
			ret_lines.insert(n);
	}
	return ret_lines;
}

//返回其操作数结果集的交集
set<TextQuery::line_no> AndQuery::eval(const TextQuery& file) const
{
	//计算其左右操作数的结果集
	set<line_no> left = lhs.eval(file), right = rhs.eval(file);
	set<line_no> ret_lines;	//保存运算结果

	//将左右操作数结果集的交集写至ret_lines
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(ret_lines, ret_lines.begin()));
	return ret_lines;
}

//返回其操作数结果集的并集
set<TextQuery::line_no> OrQuery::eval(const TextQuery& file) const
{
	//计算其左右操作数的结果集
	set<line_no> right = rhs.eval(file), ret_lines=lhs.eval(file);
	//将未在ret_lines中出现的right中的行号插入到ret_lines中
	//ret_lines.insert(right.begin(),right.end());
	//所用的编译器不支持带两个迭代器参数的insert函数，改用如下代码
	for(set<line_no>::const_iterator iter = right.begin();
		iter!=right.end();++iter)
		ret_lines.insert(*iter);
	return ret_lines;
}

