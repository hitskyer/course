#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<int> v1;
	int n;
	if(v1.empty())
	{
		cout << "请输入一串整数：\n";
		while(cin >> n)
		//	for(vector<int>::size_type ix=0;ix<6;++ix)
		//	{
				v1.push_back(n);
		//	}
		for(vector<int>::size_type ix1=0; ix1 < v1.size();++ix1)
		{
			cout << v1[ix1] << " ";
		}
	}
	vector<int> v2(v1);
	v2[0] = 100;
	cout << "把v1首位改成100后的v2是：" << endl;
	for(vector<int>::size_type ix2=0;ix2 < v2.size();++ix2)
		cout << v2[ix2] << " ";
	cout << "把v2全部置为零：\n";
	vector<int>::size_type ix3=0;
	for(vector<int>::iterator it=v2.begin(); it != v2.end(); ++it,++ix3)
	{	
//		vector<int>::size_type ix3=0;
		*it = 0;
		cout << v2[ix3] << " ";
	}
	return 0;
}	
