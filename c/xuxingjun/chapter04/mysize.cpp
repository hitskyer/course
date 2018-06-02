#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> ivec;
	ivec.push_back(0);
	for (int i = 0; i != (int)ivec.size(); ++i)
	{
		cout << ivec[i] << endl;
	}

	int arr[2];
	cout << arr << endl;
	cout << arr+1 << endl;
	cout << sizeof(int) << endl;
	return 0;
}
