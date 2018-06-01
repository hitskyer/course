#include<iostream>

#include<vector>

#include<string>

using namespace std;



int main()

{

	vector<int> ivec;

	int ival;

	cout << "读入元素: " << endl;

	while (cin >> ival)

	{	

		ivec.push_back(ival);

		if (cin.get()=='\n')

		{

			break;

		}

	}

	int *pi=new int[ivec.size()];

	int *pi1=pi; //指针pi1指向pi第一个元素

	for(vector<int>::iterator iter=ivec.begin();iter<ivec.end();++iter)

	{

		*pi1=*iter;

		++pi1;

		cout << *pi1 << " ";

	}

	delete [] pi1;

	return 0;

}
