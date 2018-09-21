#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> ivec(ia,ia+10);
	vector<int>::reverse_iterator r_iter;
	for(r_iter=ivec.rbegin();r_iter!=ivec.rend();++r_iter)
	{
		cout << *r_iter << endl;
	}
	return 0;
}