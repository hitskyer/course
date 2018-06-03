#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> ivec;
	int ni;
	int sum=0;
	while (cin >> ni){
		ivec.push_back(ni);
	}
	cout << "整数数组 ni 相邻两个数的和是：" << endl;
	if (ivec.size()==0)
	cout << "No element?!" << endl;
	for(vector<int>::size_type i=0; i<ivec.size()-1;i=i+2){
		sum=ivec[i]+ivec[i+1];
		cout << sum << " ";
	}
	cout << endl;
	if (ivec.size()%2 !=0)
	cout << "Last element is not summed and its value is : " << ivec[ivec.size()-1] << endl;
}
	
	
