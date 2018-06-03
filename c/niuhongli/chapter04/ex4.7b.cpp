#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main()
{
	vector<int> ivec1(10,20);
	vector<int> ivec2;

	for(vector<int>::iterator iter=ivec1.begin();iter<ivec1.end();++iter)
	{	
		ivec2.push_back(*iter);
	}
}

	
