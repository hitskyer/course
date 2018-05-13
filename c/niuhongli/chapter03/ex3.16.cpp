#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec(10,42);
//2:
	vector<int> ivec1(10);
	for(vector::size_type i=0; i!=ivec1.size();++i)
		ivec1[i]=42;
//3;
	vecotor<int> ivec2;
	for (int j=0; j<10; ++j)
		ivec2.push_back(42);
