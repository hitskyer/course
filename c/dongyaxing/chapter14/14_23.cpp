//复制构造函数
CheckedPtr::CheckedPtr(const CheckedPtr &c):beg(c.beg), end(c.end), curr(c.curr)
{
}

int& CheckedPtr::operator [] (const size_t index) 
{
	if(beg + index >= end || beg + index <beg)
		throw out_of_range ("invalid index");
	return *(beg + index);
}

const int& CheckedPtr::operator[](const size_t index) const
{
	if(beg + index >= end || beg + index <beg)
                throw out_of_range ("invalid index");
        return *(beg + index);
}

int& CheckedPtr::operator*()
{
	if(curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

const int& CheckedPtr::operator*() const
{
        if(curr == end)
                throw out_of_range("invalid current pointer");
        return *curr;
}

bool operator == (const CheckedPtr &lhs, const CHeckedPtr &rhs)
{
	return lsh.beg == rhs.beg && lsh.end == rhs.end && lsh.curr == rhs.curr;
}

bool operator != (const CheckedPtr &lhs, const CHeckedPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator < (const CheckedPtr &lhs, const CheckedPtr &rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr <rhs.curr;
}

bool operator >= (const CheckedPtr &lhs, const CheckedPtr &rhs)
{
	return !(lhs < rhs);
}

bool operator > (const CheckedPtr &lhs, const CheckedPtr &rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr >rhs.curr;
}

bool operator <= (const CheckedPtr &lhs, const CheckedPtr &rhs)
{
	return !(lhs > rhs);
}

CheckedPtr operator + (const CheckedPtr &lhs, const size_t n)
{
	CheckedPtr temp(lhs);
	temp.curr += n;
	if (temp.curr > end)
		throw out_of_range("too large!");
	return temp;
}

CheckedPtr operator - (const CheckedPtr& lhs, const size_t n)
{
	CheckedPtr temp(lhs);
	temp.curr -= n;
	if(temp.curr < temp.beg)
		throw out_of_range("too large n");
	return temp;
}

ptrdiff_t operator - (CheckedPtr &lsh, CheckedPtr &rhs)
{
	//检查左右操作数对象是否指向同一数组
	if(!(lhs.beg == rhs.beg && lhs.end == rhs.end))
		throw out_of_range("cant't substract");
	return lhs.curr - rhs.curr;
}

