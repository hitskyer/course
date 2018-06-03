#include <iostream>
#include<string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec(10,12);
	for(vector<int>::iterator iter=ivec.begin(); iter!=ivec.end();++iter)
	{
		*iter=(*iter)*2;
//		cout << *iter << " ";
	}
}

