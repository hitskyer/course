#include<iostream>
#include<vector>
using namespace std;

int main()
{
 	vector<int> ilist;
	for(vector<int>::size_type ix=0;ix!=4;++ix)
		ilist.push_back(ix);
	for(vector<int>::iterator iter=ilist.begin(); iter!=ilist.end(); ++iter)
		cout << *iter << " " ;
}
