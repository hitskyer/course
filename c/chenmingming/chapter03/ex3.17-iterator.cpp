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
	vector<int>::size_type total =0;
	for(vector<int>::iterator iter =num.begin();iter < num.end()-1;iter=iter+2)
	{
		cout << *iter + *(iter+1) << "\t";
		++total;
		if(total%6 ==0)
		cout << endl;
	}
	if(num.size() % 2 != 0)
		cout<< endl << "最后一个数没有可加的对象！"
		<< "it is " << *(num.end()-1) << endl;
	return 0;
}
