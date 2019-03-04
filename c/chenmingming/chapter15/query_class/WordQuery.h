#ifndef WORDQUERY_H
#define WORDQUERY_H
#include "query_base.h"
#include <string>
class WordQuery:public Query_base
{
	friend class query;
	WordQuery(std::string &s):query_word(s) {}
	WordQuery(const std::string &s):query_word(s){}
	std::set<line_no> eval(const TextQuery &t) const
	{
		return t.run_query(query_word);
	}
	std::ostream& display(std::ostream &os) const
	{
		return os << query_word;
	}
	virtual ~WordQuery();
	std::string query_word;
};

#endif

