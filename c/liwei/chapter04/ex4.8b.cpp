#include <iostream>

#include <string>

#include<vector>

using namespace std;



int main()

{

	vector<int> ivec1;

	vector<int> ivec2;

//输入两个数组的元素
cout << "Enter arrays to ivec1" << endl;

	int iv;

	while(cin>>iv)

	{

		ivec1.push_back(iv);

		if(cin.get()=='\n')

		{

			break;	

		}



	}

	cout << "Enter arrays to ivec2" << endl;

	while (cin >> iv)

	{

		ivec2.push_back(iv);

		if(cin.get()=='\n')

		{

			break;

		}

	}

// 判断是否相等
if(ivec1.size()!=ivec2.size())

	{

	 	cout << "iarr1 is not equal to iarr2" << endl;

		return -1;

	}

	else 

	{

		vector<int>::iterator iter1, iter2;

		iter1=ivec1.begin();

		iter2=ivec2.begin();

		bool flag=false;

		while (iter1<ivec1.end())

		{	

			flag=false;

 			if(*iter1==*iter2)

			{

				++ iter1;

				++ iter2;

				flag=true;

			}

			else

			{



			cout << " not equal" << endl;

			break;

			}

		}

		if (flag)

 	   	cout << "iarr1 equal to iarr2" << endl;

	}

}
