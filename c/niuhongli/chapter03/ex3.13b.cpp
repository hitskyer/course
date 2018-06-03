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
	cout << "数组整数首位相加： " << endl;
	if (ivec.size()==0){
	cout << "No element?!" << endl;
	return -1;
	}
	vector<int>::size_type legn=ivec.size()-1;
	for(vector<int>::size_type first=0;first<legn-first;++first){	
		cout << ivec[first]+ivec[legn-first] << "\t";
  	}
	cout << endl;
	if (legn % 2 ==0)
        cout << "Element in the middle is not summed and its value is : "
        << ivec[legn/2] << endl;
	return 0;
}
	
	
