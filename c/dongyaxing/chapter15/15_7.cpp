#include<iostream>
#include<string>

using namespace std;

class Item_base
{
public:
	Item_base(const std::string &book = “”,double sales_price = 0.0):isbn(book),price(sales_price){ }
	std::string book() const { return isbn; }
	virtual double net_price(std::size_t n) const { return n*price; }	//派生类重载，且使用不同的打折策略
	vittual ~Item_base();
private:
	std::string isbn;
protected:
	double price;

};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const std::string &book = "",double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):
		Disc_item(book, sales_price, qty, disc_rate) { }

	double net_price(std::size_t) const;
private:
	std::size_t min_qty;
	double discount;
};

double Bulk_item::net_price(std::size_t cnt) const
{
	if(cnt > min_qty)
		return cnt*(1-discount)*price;	//price 为基类中protected类型
	else
		return cnt*price;
}

//7题内容
class Lds_item: public Item_base
{
public:
	Lds_item(const std::string& book=“”, double sales_price = 0.0, size_t qty = 0, double sidc_rate = 0.0):
		item_base(book, sales_price), max_qty(qty), discount(disc_rate) { }
	double Lds_item::net_price(size_t cnt) const
	{
		if(cnt<=max_qty)
			return cnt*(1-discount)*price;
		else
			return cnt*price-max_qty*discount*price;
	}
private:
	zise_t max_qty;
	double discount;
};

//保存折扣率和可实行折扣策略的数量
//派生类将使用这些数据实现定价策略
class Disc_item : public Item_base
{
public:
	Disc_item (std::string &book = "",double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):
		Item_base(book, sales_price),quantity(qty),discount(disc_rate) { }
	
	virtual double net_price(size_t) const = 0;	//自行添加virtual,答案中没有。纯虚函数的目的：放置用户创建Disc_item对象
	std::pair<size_t, double> discount_policy() const
	{
		return std::make_pair(quantity, discount);
	}
protected:
	size_t quantity;
	double discount;
};

//22题内容
class Lds_item_2 : public Disc_item
{
public:
	Lds_item_2(const std::string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):
		Disc_item(book, sales_price, qty, disc_rate) { }

	//重定义基类版本以实现有限折扣策略
	//对于低于上限的购书量 使用折扣价格
	double net_price(size_t cnt) const
	{
		if(cnt<= quantity)
			return cnt*(1-discount)*price;
		else
			return cnt*price - quantity*discount*price;
	}
};

int main()
{
	Item_base b;
	Bulk_item d;
	return 0;
}
