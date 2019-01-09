#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "query.h"
#include "query_base.h"
class NotQuery :public Query_base
{
	friend query operator~(const query &);
	NotQuery(query q):qury(q){}
	std::set<line_no> eval(const TextQuery&) const;
	std::ostream& display(std::ostream &os) const
	{
		return os << "~(" << qury << ")";
	}
	virtual ~NotQuery();
	const query qury;
};

#endif

