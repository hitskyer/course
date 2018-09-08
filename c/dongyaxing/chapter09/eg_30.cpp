#include<iostream>
#include<vector>

using namespace std;

int main()
{
//	int arr[]={1,2,3,4,5,6,7,8};
	vector<int> ivec;

	cout<<"ivec中，没有任何数据时："<<endl;
	cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;
	
	for(vector<int>::size_type ix = 0;ix!=8;++ix)
	{
		ivec.push_back(ix+1);
	}
	cout<<"ivec中，有8个整数时："<<endl;
	cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	ivec.push_back(9);
	cout<<"ivec中，添加一个‘9’数字时："<<endl;
	cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	while(ivec.size()!=ivec.capacity())
	{
		ivec.push_back(1);
	}
	cout<<"ivec中，用完capacity容量时："<<endl;
	cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	ivec.push_back(10);
        cout<<"ivec中，添加一个‘10’数字时："<<endl;
        cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;
	
	ivec.reserve(100);
	cout<<"ivec的capacity设置为100时："<<endl;
	cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	while(ivec.size()!=ivec.capacity())
        {
                ivec.push_back(0);
        }
        cout<<"ivec中，用完capacity容量时："<<endl;
        cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	ivec.push_back(11);
        cout<<"ivec中，添加一个‘11’数字时："<<endl;
        cout<<"size: "<<ivec.size()<<" , capacity: "<<ivec.capacity()<<endl<<endl;

	cout<<"结论：当用完capacity时，再添加元素，空间会添加原来的一倍。"<<endl<<endl;

	return 0;
}
