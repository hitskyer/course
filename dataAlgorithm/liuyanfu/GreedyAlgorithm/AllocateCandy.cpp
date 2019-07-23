#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct AllocRet
{
	vector<int> vCandySize;
	vector<int> vPeopleExpect;
};


void bSort(int* arr, int nSize)
{
	for(int i = 0; i < nSize - 1; ++i)
	{
		for(int j = 0; j < nSize - 1 - i; ++j)
		{
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}


void AllocCandy(int* candySize, int m, int* peopleExpect, int n, AllocRet* ret)
{
	bSort(candySize, m);
	bSort(peopleExpect, n);
	int j = 0;
	for(int i = 0; i < n; ++i)
	{
		while(j < m)
		{
			if(peopleExpect[i] <= candySize[j])
			{
				ret->vCandySize.push_back(candySize[j++]);
				ret->vPeopleExpect.push_back(peopleExpect[i]);
				break;
			}
			++j;
		}
		if(j == m)
			break;
	}
}

int main()
{
	int candyNum, peopleNum;
	bool confidtion = true;
	while(true)
	{
		cout << "请输入糖果的个数： ";
		cin >> candyNum;
		cout << "请输入人的个数： ";
		cin >> peopleNum;
		if(candyNum > peopleNum)
		{
			cout << "Candy Num should less than People Num, Please re-enter" << endl;
			cin.clear();
		}
		else
			break;
	}
	int* candySize = new int[candyNum];
	int* peopleExpect = new int[peopleNum];
	cout << "请输入每个糖果的大小：";
	for(int i = 0; i < candyNum; ++i)
	{
		cin >> candySize[i];
	}
	cout << "请输入每个人期望得到糖果的大小：";
	for(int i = 0; i < peopleNum; ++i)
	{
		cin >> peopleExpect[i];
	}

	AllocRet ret;
	AllocCandy(candySize, candyNum, peopleExpect, peopleNum, &ret);
	for(size_t i = 0; i < ret.vCandySize.size(); ++i)
	{
		cout << ret.vCandySize[i] << " ";
	}
	cout << endl;
	for(size_t i = 0; i < ret.vPeopleExpect.size(); ++i)
	{
		cout << ret.vPeopleExpect[i] << " ";
	}
	cout << endl;
	delete []candySize;
	delete []peopleExpect;
	return 0;
}