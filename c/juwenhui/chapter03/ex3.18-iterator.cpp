#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec(10,15);
	for(vector<int>::iterator iter=ivec.begin();iter != ivec.end();++iter)
	{
		*iter = 2*(*iter);
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
