#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	// int ia[] = {1,2,3,4,5,6};
	// fill(ia,ia+5,9);
	// for(int i = 0; i != 6;++i)
	// {
	// 	cout << ia[i] << " ";
	// }
	// cout << endl;
	// int ib[] = {1,2,3,4,5,6};
	// fill_n(ib,5,9);
	// for(int i = 0; i != 6;++i)
	// {
	// 	cout << ib[i] << " ";
	// }
	// cout << endl;
	// return 0;
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	fill_n(back_inserter(ivec),5,3);
	for(vector<int>::iterator it = ivec.begin();it != ivec.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}