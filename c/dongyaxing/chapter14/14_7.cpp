#include<iostream>
#include<pair>
#include<vector>

struct Data
{
	//填充内容
	int Year;
	int Month;
	int Day;
};

class CheckoutRecord
{
	friend ostream& operator << (ostream& out, const CheckoutRecord& c);
	friend istream& operator >> (istream& in, CheckoutRecord& c);
public:
	pair<string, string>& operator[] (const vector<pair<string, string>* >::size_type index)
	{ return *wait_list.at(index); }
	
	const pair<string, string>& operator[] (const vector<pair<string, string>* >::size_type index) const
	{ return *wait_list.at(index); }
private:
	double book_id;
	string title;
	Data data_borrowed;
	Data data_due;
	pair<string, string> borrower;
	vector< pair<string, string>* >wait_list;
};

ostream& operator << (ostream& out, const CheckoutRecord& c)
{
	out << c.book_id << "\t" << c.title << std::endl 
		<< "data borrowed: " <<c.data_borrow << std::endl
		<< "data due: "<< c.data_due << std::endl
		<< "borrower: " <<c.borrower.first << ","
		<< c.borrower.second << std::endl;
	out<<"wait_list:"<< std::endl;
	for(vector<pair<string, string>* >::const_iterator iter = c.wait_list.begin();
		iter != wait_list.end(); ++iter)
		out<<"\t"<<(*iter)->first <<", "<<(*iter)->second << std::endl;
	return out;
}

istream& operator >> (istream& in, CheckoutRecord& c)
{
	in >> c.book_id >> c.title >> c.data_borrowed >> c.data_due
		>> c.borrower.first >> c.borrower.second;
	if(!in)
	{	c = CheckoutRecord();
		return in;
	}

	c.wait_list.clear();
	while(in)
	{
		pair<string, string> *ppa = new pair<string, string>;
		in >> ppa -> first >> ppa -> second;
		if(!in)
			return in;
		c.wait_list.push_back(ppa);
	} 
	return in;
}

CheckoutRecord& CheckoutRecord::operator = (const CheckoutRecord& rhs)
{
	book_id = rhs.book_id;
	title = rhs.title;
	data_borrowed = rhs.data_borrowes;
	data_due = rhs.data_due;
	borrower = rhs.borrower;

	wait_list.clear();
	for(vector<pair<string, string>* > ::const_iterator it = rhs.wait_list.begin();
		it != rhs.wait_list.end(); ++it)
	{
		pair<string, string> *ppa = new pair<string, string>;
		*ppa = **it;   //实现深层复制
		wait_list.push_back(ppa);
	}	
	return *this;
}

pair<string, string>& CheckoutRecord::operator[] (const vector<pair<string, string>* >::size_type index)
        { return *wait_list.at(index); }

const pair<string, string>& CheckoutRecord:: operator[] (const vector<pair<string, string>* >::size_type index) const
        { return *wait_list.at(index); }

int main()
{
	CheckoutRecord CRD;
	std::cout << CRD <<std::string;
	return 0;
}
