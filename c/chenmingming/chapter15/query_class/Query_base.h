#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "TextQuery.h"
#include <iostream>

class Query_base
{
	friend class query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base(){}
//	Query_base(void);
private:
	virtual std::set<line_no> eval(const TextQuery&) const = 0;
	virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

#endif

