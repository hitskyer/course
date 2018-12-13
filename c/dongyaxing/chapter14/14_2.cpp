class Sales_item
{
	friend std::istream& operator >> (std::istream&, Sales_item&);
	friend std::ostream& operator << (std::ostream&, Sales_item&);
public:
	Sales_item& operator += (const Sales_item&);

};
Sales_item operator + (const Sales_item&, const Sales_item&);
