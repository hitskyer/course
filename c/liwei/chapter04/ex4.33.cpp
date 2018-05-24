#include<iostream>

#include<vector>

using namespace std;



int main()

{

	vector<int> ivec;

	cout << "Enter numbers:" << endl;

	int ival;

	while(cin >> ival)

	{

		ivec.push_back(ival);

		if (cin.get()=='\n')

		break;

	}

	

	int *newarr= new int[ivec.size()];

	int *pi=newarr;

	for(vector<int>::iterator iter=ivec.begin();iter<ivec.end();++iter)

	{

		*pi=*iter;

		cout << *pi << endl;

		++pi;

	}

	delete [] newarr;

}
