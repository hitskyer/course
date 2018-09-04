#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
//长度为0
	cout << " ivec_size: " << ivec.size() << endl;
	cout << " ivec_capacity: " << ivec.capacity() << endl;   
 // 输入5个元素
        for(vector<int>::size_type ix=0; ix!=5;++ix)
           	ivec.push_back(ix);
	 cout << " ivec_size: " << ivec.size() << endl;
         cout << " ivec_capacity: " << ivec.capacity() << endl;
// 将现有容量用完
	 while(ivec.size()!=ivec.capacity())
		ivec.push_back(2);
	 cout << " ivec_size: " << ivec.size() << endl;
	 cout << " ivec_capacity: " << ivec.capacity() << endl;
// 新添加1个元素
         ivec.push_back(2);
	 cout << " ivec_size: " << ivec.size() << endl;
   	cout << " ivec_capacity: " << ivec.capacity() << endl;
// 设置容量大小为20
	ivec.reserve(20);
	cout << " ivec_size: " << ivec.size() << endl;
	cout << " ivec_capacity: " << ivec.capacity() << endl;
// 将现有容量用完
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(2);
	 cout << " ivec_size: " << ivec.size() << endl;
	cout << " ivec_capacity: " << ivec.capacity() << endl;
// 新添加1个元素
	ivec.push_back(0);
        cout << " ivec_size: " << ivec.size() << endl;
	cout << " ivec_capacity: " << ivec.capacity() << endl;
	return 0; 
}
