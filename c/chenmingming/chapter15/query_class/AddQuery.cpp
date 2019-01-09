#include "AddQuery.h"
#include "TextQuery.h"
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
AddQuery::~AddQuery()
{
}

std::set<TextQuery::line_no> AddQuery::eval(const TextQuery& file) const
{
	std::set<TextQuery::line_no> right = rhs.eval(file),
								 left = lhs.eval(file);
	std::set<TextQuery::line_no> ret_lines;
	set_intersection(left.begin(),left.end(),
					 right.begin(),right.end(),
					 inserter(ret_lines, ret_lines.begin()));
	return ret_lines;

}