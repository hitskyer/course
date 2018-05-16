#include<iostream>
using namespace std;
int main()
{
	string s1;
	cout << "s1字符个数为：" << s1.size() <<endl;
	if(s1.empty())
	{	
		cout << "请输入s1字符：\n";
		cin >> s1;
		string s2(s1);
		cout << "s2为：" << s2 << endl;
	}
	string s3("s3");
	cout << "请输入s3：\n";
	getline(cin,s3);
	cout << "s3为：" << s3 <<endl;
	string s4(5,'a');
	string s5 = s3 + " " + s4;
	cout << "s5 is " << s5 <<endl;
	s5[0] = 'A';
	cout << "修改后的s5 is " << s5 <<endl;
	for(string::size_type ix=0;ix < s5.size();++ix)
		if(islower(s5[ix]))
			s5[ix]=toupper(s5[ix]);
	cout << "转换大写后的s5是：" << s5 <<endl;
	return 0;
}
