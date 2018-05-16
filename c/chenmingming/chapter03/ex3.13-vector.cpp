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
	cout << "相邻数据相加结果为：" << endl;
	for(vector<int>::size_type total =0;total<num.size()-1;total=total+2)
	{
		cout << num[total] + num[total+1] << "\t";
		if((total+1)%6 ==0)
		cout << endl;
	}
	if(num.size() % 2 != 0)
		cout<< endl << "最后一个数没有可加的对象！"
		<< "it is " <<num[num.size()-1] << endl;
	return 0;
}
