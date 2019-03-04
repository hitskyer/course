#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	istream_iterator<int> cin_iter(cin),end;
	vector<int> ivec(cin_iter,end);
	sort(ivec.begin(),ivec.end());
	ostream_iterator<int> print(cout," ");
	unique_copy(ivec.begin(),ivec.end(),print);
	return 0;
}