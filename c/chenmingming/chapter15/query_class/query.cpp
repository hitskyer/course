#include "query.h"
#include "TextQuery.h"
#include "AddQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"
inline query& query::operator=(const query &rhs)
{
    ++*rhs.use;
    decr_use();
    q = rhs.q;
    use = rhs.use;
    return *this;
}
inline std::ostream& operator<<(std::ostream& os, const query &q)
{
    return q.display(os);
}

inline query::query(const std::string &s):q(new WordQuery(s)),use(new size_t(1)) { }
inline query operator&(const query &lhs, const query &rhs)
{
	return new AddQuery(lhs,rhs);
}

inline query operator|(const query &lhs,const query &rhs)
{
	return new OrQuery(lhs,rhs);
}

inline query operator~(const query &oper)
{
	return new NotQuery(oper);
}

