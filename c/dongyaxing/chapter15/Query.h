#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.cpp"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

class Query_base
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base() { }	//构造函数
private:
	virtual set<line_no> eval (const TextQuery&) const = 0;	//纯虚函数
	virtual ostream& display(ostream& = cout) const = 0;
};

//管理Query_base继承层次的句柄类
class Query
{
	//这些操作符需要访问Query_base*构造函数
	friend Query operator ~ (const Query &);
	friend Query operator | (const Query&, const Query&);
	friend Query operator & (const Query&, const Query&);
public:
	Query(const string&);	//建立新的wordQuery对象
	//管理指针及使用计数的复制控制成员
	Query(const Query &c):q(c.q),use(c.use) { ++*use; }
	~Query() { decr_use(); }
	Query& operator = (const Query&);

	//接口函数：将调用相应的Query_base操作
	set<TextQuery::line_no> eval(const TextQuery &t) const { return q->eval(t); }
	ostream &display(ostream &os) const { return q->display(os); }

private:
	Query(Query_base *query):q(query),use(new size_t(1)) { } 
	
	Query_base *q;
	size_t *use;
	void decr_use()
	{ if(--*use == 0) { delete q; delete use; } }
};

inline Query& Query::operator = (const Query &rhs)
{
	++*rhs.use;
	decr_use();
	q = rhs.q;
	use = rhs.use;
	return *this;
}

inline ostream& operator <<( ostream &os, const Query &q)
{
	return q.display(os);
}

class WordQuery :public Query_base
{
	friend class Query;	//Query使用WordQuery构造函数
	WordQuery(const string &s):query_word(s) { }
	
	//具体类WordQuery定义所有继承而来的纯虚函数
	set<line_no> eval (const TextQuery &t) const
	{ return t.run_query(query_word); }
	ostream &display (ostream &os) const
	{ return os<<query_word; }
	string query_word;	//要查找的单词
};

inline Query::Query(const string &s) : q(new WordQuery(s)),use(new size_t(1)) { }

class NotQuery : public Query_base
{
	friend Query operator ~ (const Query &);
	NotQuery(Query q):query(q) { }

	//具体类NotQuery定义所有继承而来的纯虚函数
	set<line_no>  eval (const TextQuery &t) const;
	ostream& display(ostream &os) const
	{ return os << "~(" << query << ")"; }
	const Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(Query left, Query right, string op) : lhs(left), rhs(right), oper(op) { }

	//抽象类BinaryQuery不定义eval
	ostream& display(ostream &os) const
	{ return os << "(" << lhs << " " << oper << " "<<rhs<<")"; }
	const Query lhs,rhs;	//左右操作数
	const string oper;	//操作符
};

class AndQuery :public BinaryQuery
{
	friend Query operator & (const Query&, const Query&);
	AndQuery(Query left, Query right) : BinaryQuery(left, right, "&") { }
	//具体类AndQuery继承display并保持为虚函数
	set<line_no> eval(const TextQuery&) const;
};

class OrQuery :public BinaryQuery
{
	friend Query operator | (const Query&, const Query&);
	OrQuery(Query left, Query right):BinaryQuery(left, right, "|")  { }
	//具体类AndQuery继承display并保持为虚函数
	set<line_no> eval(const TextQuery&) const;
};

inline Query operator& (const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}

inline Query operator| (const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}

inline Query operator~ (const Query &oper)
{
	return new NotQuery(oper);
}
#endif
