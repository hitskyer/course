std::istream& read(std::istream &is, Sales_item& obj)
{
	double price;
	is>>obj.isbn>>obj.units_sold>>price;
	if(is)
		obj.revenue = obj.units_sold * price;
	else
		obj = Salse_item();
	return is;
}

class Sales_item
{
public:
	friend istream& read(std::istream&, Sales_item&);
	bool same_isbn(const Sales_item &rhs) const
	{ return isbn = rhs.isbn; }

	Sales_item(const std::string &book=""):
		isbn(book), units_sold(0), revenue(0.0) { }

private:
	std::string isbn;
	int units_sold;
	double revenue;
};
