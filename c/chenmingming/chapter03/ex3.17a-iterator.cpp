#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> num;
	int x;
	cout << "please enter some number, ctrl+D to end!"<< endl;
	while(cin >> x)
	{
		num.push_back(x);
	}
	if(num.size()==0)
        {
                cout << "no element ?" << endl;
                return -1;
        }
	cout << "首尾数据相加结果为：" << endl;
	vector<int>::size_type total = 0;
	vector<int>::iterator front,back;
	for(vector<int>::iterator iter1=num.begin(),iter2 = num.end()-1; iter1 < iter2;++iter1,--iter2,front=iter1,back=iter2)
	{
		cout << *iter1 + *iter2 << " ";
		++total;
//		front = iter1;
//		back = iter2;
		if(total%6 ==0)
		cout << endl;
	}
	if(front == back)
		cout<< endl << "最中间一个数没有可加的对象！"
			<< "it is " << *front << endl;
	return 0;
}
