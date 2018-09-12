#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout<<"小写 转换为 大写"<<endl;
	string str("my name is jessie !");
	cout<<"原始："<<str<<endl<<endl;

	for(string::iterator it=str.begin();it!=str.end();++it)
	{
		*it=toupper(*it);
	}
	cout<<"变换后："<<str<<endl<<endl;
	return 0;
}


