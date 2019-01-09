#ifndef ORQUERY_H
#define ORQUERY_H
#include "BinaryQuery.h"
class OrQuery : public BinaryQuery
{
	friend query operator|(const query&, const query&);
	OrQuery(query left, query right):BinaryQuery(left,right,"|"){}
	std::set<line_no> eval(const TextQuery&) const;
	virtual ~OrQuery();
};

#endif
