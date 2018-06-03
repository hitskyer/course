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
	for(vector<int>::size_type total =0;total<num.size()/2;++total)
	{
		cout << num[total] + num[num.size()-total-1] << "\t";
		if((total+1)%6 ==0)
		cout << endl;
	}
	if(num.size() % 2 != 0)
		cout<< endl << "最中间一个数没有可加的对象！"
		<< "it is " <<num[(num.size()-1)/2] << endl;
	return 0;
}
