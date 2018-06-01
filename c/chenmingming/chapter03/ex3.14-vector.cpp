#include<iostream>
#include<vector>
#include<string>
//#include<cctype>
using namespace std;
int main()
{
	string s;
	vector<string> S;
	cout << "请输入一段english文字：" << endl;
	while(cin >> s)
	{
		S.push_back(s);
	}
	if(S.size() == 0)
	{
		cout << "no string ?" << endl;
		return -1;
	}
	cout << "转换大写的字句是：" << endl;
	string t;
	for(vector<int>::size_type ix =0;ix < S.size();++ix)
	{
		t= S[ix];
		for(string::size_type index =0;index < t.size();++index)
		{
			if(islower(t[index]))
			t[index] = toupper(t[index]);
		}
		cout << t << " ";
		if((ix+1)%8 == 0)
		cout << endl;
	}
	return 0;
}
