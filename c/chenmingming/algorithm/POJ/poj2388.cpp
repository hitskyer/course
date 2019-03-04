#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int *milk = new int[num];
	for(int i = 0; i != num; ++i)
	{
		cin >> milk[i];
	}
	sort(milk,milk+num);
	cout << milk[num/2];
	delete [] milk;
	milk = NULL;
	return 0;
}