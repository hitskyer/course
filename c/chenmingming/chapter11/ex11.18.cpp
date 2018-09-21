#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;
int main()
{
	ofstream filea("filea.txt");
	ofstream fileb("fileb.txt");
	if(!filea || !fileb)
	{
		cout << "can not open output file: " << endl;
		return EXIT_FAILURE;
	}
	cout << "enter some ints: " << endl;
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter_a(filea," ");
	ostream_iterator<int> out_iter_b(fileb,"\n");
	while(in_iter != eof)
	{
		if(*in_iter % 2 != 0)
		{
			*out_iter_a = *in_iter;
			++out_iter_a;
		}
		else
		{
			*out_iter_b = *in_iter;
			++out_iter_b;
		}
		++in_iter;
	}
	filea.close();
	fileb.close();
	return 0;
}