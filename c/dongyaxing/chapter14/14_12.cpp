//方案一，先定义+=，用+调用+=
Sales_item operator += (const Sales_item& rhs )
{
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
}

Sales_item operator + (const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

//方案二，先定义+，用+= 调用+
Sales_item operator + (const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Salse_item operator += (Sales_item& lhs, const Sales_item& rhs)
{
	lhs = lhs + rhs;
	return lhs;
}
//方案二中，需要创建和撤销一个临时变量lhs，不如方案一合理

Sales_item& Sales_item::operator -= (const Sales_item& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}
Sales_item operator - (const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

Sales_item& Sales_item::operator = (const string& str)
{
	isbn = str;
	return *this;
}
