#include <iostream>
#include <set>
#define LEN 5
using namespace std;

int main()
{
	// 正确数据
	//int actor[5] = {1,2,3,4,5};
	//int refer[5] = {2,3,4,5,0};
	// 重复推荐者
	int actor[5] = {1,2,3,4,5};
	int refer[5] = {2,4,4,5,0};
	// 有环的问题数据
	//int actor[5] = {1,2,3,4,5};
	//int refer[5] = {2,3,4,5,1};
	// 问题数据: 6号，并不是使用者。所以也能作为推荐者
	//int actor[5] = {1,2,3,4,5};
	//int refer[5] = {2,3,4,5,6};

	set<int> key;
	int i = 0;
	int size_pre = 0;
	int size_cur = 0;
	for (int j = 0; j < LEN; ++j)
	{
		if (refer[i] == actor[j])
		{
			i = j;
			j = -1;
			size_pre = key.size();
			key.insert(actor[i]);
			size_cur = key.size();
			if (size_cur == size_pre)
			{
				cout << "Error Data because 【Circle data】!" << endl;
				system("pause");
				return 0;
			}
		}
		else if (refer[i] == 0)
		{
			cout << "find the final referrer_id : " << actor[i] << endl;
			system("pause");
			return 0;
		} 
	}
	cout << "Error Original Data!" << endl;
	system("pause");
	return 0;
}