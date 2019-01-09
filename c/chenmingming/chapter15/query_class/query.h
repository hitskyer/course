#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include "Query_base.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>

class query
{
	friend query operator~(const query &);
	friend query operator|(const query&, const query&);
	friend query operator&(const query&, const query&);
public:
	query(const std::string&);
	query(const query &c):q(c.q),use(c.use){ ++*use;}
	~query(){ decr_use();}
	query& operator=(const query&);
	friend std::ostream& operator<<(std::ostream& os, const query &q);
	std::set<TextQuery::line_no> eval(const TextQuery &t) const
	{	return q->eval(t);}
	std::ostream &display(std::ostream &os) const
	{	return q->display(os);}
private:
	query(Query_base *qur):q(qur),use(new std::size_t(1)){}
	Query_base *q;
	std::size_t *use;
	void decr_use()
	{
		if(--*use == 0)
		{	delete q;	delete use;}
	}
};
#endif

