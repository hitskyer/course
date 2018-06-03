#include <iostream>
#include <vector>
using namespace std;
int main() 
{
	int a[7] = {0,1,2,3,4,5,6};
	vector<int> ivec(a, a+3);
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end(); ++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}
