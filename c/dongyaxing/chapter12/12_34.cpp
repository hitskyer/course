Sales_item add(const Sales_item &obj1, const Sales_item &obj2)
{
	if(!obj1.same_isbn(obj2))
		return obj1;
	Sales_item temp;
	temp.isbn = obj1.isbn;
	temp.units_sold - obj1.units_sole + obj2.units_sold;
	temp.revenue = obj1.revenue + obj2.revenue;
	return temp;
}

class Sales_item
{
	friend Sales_item add(const Sales_item&, const Sales_item&);
	bool same_isbn(const Sales_item &rhs) const
	{ return isbn == rhs.isbn; }
	
	Sales_item(const std::string &book = ""):
		isbn(book),units_sold(0),revenue(0.0) { }
	Sales_item(std::istream &is)
	{ cin>>isbn>>units_sold>>revenue;}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
