#ifndef ADDQUERY_H
#define ADDQUERY_H
#include "BinaryQuery.h"
class AddQuery : public BinaryQuery
{
	friend query operator&(const query&, const query&);
	AddQuery(query left, query right):BinaryQuery(left, right, "&"){}
	std::set<line_no> eval(const TextQuery&) const;
	virtual ~AddQuery();
};

#endif
