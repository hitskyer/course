#include <iostream>

#include <string>

using namespace std;



int main()

{

	const int array_size=5;



	int iarr1[array_size],iarr2[array_size];

	int inarr;
//输入两个数组的元素
cout << "Enter "<< array_size << "arrays to iarr1" << endl;

	for(size_t i=0; i<array_size;++i)

	{

		cin >>inarr;

		iarr1[i]=inarr;

	}

	cout << "Enter " << array_size << "arrays to iarr2" << endl;

	for(size_t j=0; j<array_size;++j)

	{

		cin >> inarr;

		iarr2[j]=inarr;

	}
// 判断是否相等
for(size_t ix=0; ix < array_size; ++ix)

		if (iarr1[ix]!=iarr2[ix])

		{

		cout << "iarr1 is not equal to iarr2" << endl;

		return -1;

		}

		cout << "iarr1 equal to iarr2" << endl;

		return 0;

}
