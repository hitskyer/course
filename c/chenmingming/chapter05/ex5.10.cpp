#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	bitset<30> test;
	test[27] = 1;
	cout << test << endl;
	test[27] = 0;
	cout << test << endl;
	
}
