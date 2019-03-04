#include<vector>
#include<iterator>
#include<iostream>
#include<fstream>
#include<exception>
#include<Sales_item.h>
using namespace std;
int main(int argc, char** argv)
{
	ifstream openfile;
	openfile.open(argv[1]);
	if(!openfile)
		throw runtime_error("open file failure!");
	istream_iterator<Sales_item> item_iter(openfile),end;
	Sales_item sum;
	sum = *item_iter++;
	while(item_iter != end)
	{
		if(item_iter->same_isbn(sum))
			sum += *item_iter;
		else
		{
			cout << sum << endl;
			sum = *item_iter;
		}
		++item_iter;
	}
	cout << sum << endl;
	return 0;
}