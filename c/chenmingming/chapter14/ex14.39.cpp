#include<vector>
#include<string>
#include<functional>
#include<iostream>
using namespace std;
int main()
{
	string str[5]={"a","ab","aw","ads","de"};
	vector<string> svec(str,str+5);
	greater_equal<string::size_type> geq_str_size;
	for(vector<string>::iterator it = svec.begin();
		it != svec.end(); ++it)
	{
		if(geq_str_size(it->size(),3))
			cout << *it << endl;
	}
	return 0;
}