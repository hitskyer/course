#ifndef BINARYQUERY_H
#define BINARYQUERY_H
#include "query_base.h"
#include "query.h"

class BinaryQuery :	public Query_base
{
protected:
	BinaryQuery(query left, query right, std::string op):lhs(left),rhs(right),oper(op){}
	std::ostream& display(std::ostream &os) const
	{
		return os << "(" << lhs << " " << oper << " " << rhs << ")";
	}
	virtual ~BinaryQuery();
	const query lhs, rhs;
	const std::string oper;
};

#endif

