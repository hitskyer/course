#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> ivec;
	for(vector<int>::size_type i = 0; i!= 10; ++i)
	{
		ivec.push_back(i);
	}
	vector<int>::reverse_iterator r_iter;
	for(r_iter = ivec.rbegin(); r_iter != ivec.rend(); ++r_iter)
	{
		cout << *r_iter << " ";
	}
	return 0;
}