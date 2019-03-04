#include "OrQuery.h"


OrQuery::~OrQuery()
{
}

std::set<TextQuery::line_no> OrQuery::eval(const TextQuery& file) const
{
	std::set<TextQuery::line_no> right = rhs.eval(file),
								ret_lines = lhs.eval(file);
	ret_lines.insert(right.begin(), right.end());
	return ret_lines;
}